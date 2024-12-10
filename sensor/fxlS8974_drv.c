/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "math.h"
#include "fsl_fxls.h"
#include "fsl_tpm.h"
#include "pin_mux.h"

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#include <stdio.h>
#include <stdint.h>

#include "slcd_engine.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* The Flextimer instance/channel used for board */
#define BOARD_TIMER_BASEADDR       TPM0
#define BOARD_FIRST_TIMER_CHANNEL  4U
#define BOARD_SECOND_TIMER_CHANNEL 2U
/* Get source clock for TPM driver */
#define BOARD_TIMER_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_McgIrc48MClk)
#define TIMER_CLOCK_MODE         1U
/* I2C source clock */
#define I2C_BAUDRATE 100000U

#define I2C_RELEASE_SDA_PORT  PORTE
#define I2C_RELEASE_SCL_PORT  PORTE
#define I2C_RELEASE_SDA_GPIO  GPIOE
#define I2C_RELEASE_SDA_PIN   25U
#define I2C_RELEASE_SCL_GPIO  GPIOE
#define I2C_RELEASE_SCL_PIN   24U
#define I2C_RELEASE_BUS_COUNT 100U
/* Upper bound and lower bound angle values */
#define ANGLE_UPPER_BOUND 80U
#define ANGLE_LOWER_BOUND 5U

#define low_g  0.15
#define high_g 0.85



#define ACCEL_2G_SENS          (0.000976)   /* Sensitivity factor for 2G FS */
#define ACCEL_4G_SENS          (0.001953)   /* Sensitivity factor for 4G FS */
#define ACCEL_8G_SENS          (0.003906)   /* Sensitivity factor for 8G FS */
#define ACCEL_16G_SENS         (0.007813)   /* Sensitivity factor for 16G FS */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/



/*******************************************************************************
 * Variables
 ******************************************************************************/
/* FXLS device address */
const uint8_t g_accel_address = 0x18U;
float correction=0U;

/*******************************************************************************
 * Code
 ******************************************************************************/

static void i2c_release_bus_delay(void)
{
    uint32_t i = 0;
    for (i = 0; i < I2C_RELEASE_BUS_COUNT; i++)
    {
        __NOP();
    }
}

void BOARD_I2C_ReleaseBus(void)
{
    uint8_t i = 0;
    gpio_pin_config_t pin_config;
    port_pin_config_t i2c_pin_config = {0};

    /* Config pin mux as gpio */
    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.mux        = kPORT_MuxAsGpio;

    pin_config.pinDirection = kGPIO_DigitalOutput;
    pin_config.outputLogic  = 1U;
    CLOCK_EnableClock(kCLOCK_PortE);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SCL_PIN, &i2c_pin_config);
    PORT_SetPinConfig(I2C_RELEASE_SDA_PORT, I2C_RELEASE_SDA_PIN, &i2c_pin_config);

    GPIO_PinInit(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, &pin_config);
    GPIO_PinInit(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, &pin_config);

    /* Drive SDA low first to simulate a start */
    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    /* Send 9 pulses on SCL and keep SDA high */
    for (i = 0; i < 9; i++)
    {
        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
        i2c_release_bus_delay();
        i2c_release_bus_delay();
    }

    /* Send stop */
    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
    i2c_release_bus_delay();
}
/* Initialize timer module */
static void Timer_Init(void)
{
    /* convert to match type of data */
    tpm_config_t tpmInfo;
    tpm_chnl_pwm_signal_param_t tpmParam[2];

    /* Configure tpm params with frequency 24kHZ */
    tpmParam[0].chnlNumber       = (tpm_chnl_t)BOARD_FIRST_TIMER_CHANNEL;
    tpmParam[0].level            = kTPM_LowTrue;
    tpmParam[0].dutyCyclePercent = 0U;

    tpmParam[1].chnlNumber       = (tpm_chnl_t)BOARD_SECOND_TIMER_CHANNEL;
    tpmParam[1].level            = kTPM_LowTrue;
    tpmParam[1].dutyCyclePercent = 0U;

    /* Initialize TPM module */
    TPM_GetDefaultConfig(&tpmInfo);
    TPM_Init(BOARD_TIMER_BASEADDR, &tpmInfo);

    CLOCK_SetTpmClock(1U);

    TPM_SetupPwm(BOARD_TIMER_BASEADDR, tpmParam, 2U, kTPM_EdgeAlignedPwm, 1000U, BOARD_TIMER_SOURCE_CLOCK);
    TPM_StartTimer(BOARD_TIMER_BASEADDR, kTPM_SystemClock);
}

/* Update the duty cycle of an active pwm signal */
static void Board_UpdatePwm(uint16_t x, uint16_t y)
{
    /* Updated duty cycle */
   TPM_UpdatePwmDutycycle(BOARD_TIMER_BASEADDR, (tpm_chnl_t)BOARD_FIRST_TIMER_CHANNEL, kTPM_EdgeAlignedPwm, x);
   TPM_UpdatePwmDutycycle(BOARD_TIMER_BASEADDR, (tpm_chnl_t)BOARD_SECOND_TIMER_CHANNEL, kTPM_EdgeAlignedPwm, y);
}


float FXLS8974_get_data(fxls_handle_t *fxlsHandle,  uint8_t dataScale, int count) {




	fxls_accel_data_t accelData = {0};
    float y_data =0;
    float x_data=0;
    float z_data=0;
    int16_t xAngle          = 0;
    int16_t yAngle          = 0;
    int16_t zAngle          = 0;
    int16_t xDuty           = 0;
    int16_t yDuty           = 0;


		        /* Get new accelerometer data. */
		        if (FXLS_ReadAccelData(fxlsHandle, &accelData) != kStatus_Success)
		        {
		            return -1;
		        }

		        /* Convert raw data to g (normalize to 0-90 degrees). No negative angles. */
		        x_data=accelData.accelX*correction;
		        if (x_data < 0)
		        {

		            x_data = -1*x_data;
		        }
		        y_data=accelData.accelY*correction;
		        if (y_data < 0)
		        {
		          //  yAngle *= -1;
		            y_data= -1*y_data;
		        }
		        z_data=accelData.accelZ*correction;
		        if (z_data < 0)
		        {
		       // zAngle *= -1;
		        z_data = -1* z_data;
		        }

		        /* Update duty cycle to turn on LEDs when directional G < 0.1*/
		        if (x_data < low_g )
		        {
		            xDuty = 0;
		        }
		        if (y_data < low_g)
		        {
		            yDuty = 0;
		        }
		        /* Update duty cycle to turn on LEDs when directional  0.9< G < 0.1*/
		        if ((x_data > low_g ) && (x_data < high_g) )
		        {
		            xDuty = 35;
		        }
		        if ((y_data > low_g ) && (y_data < high_g) )
		        {
		      	     yDuty = 25;
		        }
		        /* Update duty cycle to turn on LEDs when directional G>0.9 */
		        if (x_data > high_g)
		        {
		     	     xDuty = 75;
		        }
		        if (y_data > high_g)
		     	{
		     	     yDuty = 75;
		        }


		        Board_UpdatePwm(xDuty, yDuty);

		        	if(count==100){
		        			/* Print out the angle data. */
		        			PRINTF("x= %f y = %f  z=%f   \r\n", x_data, y_data, z_data);

		        	}


	return y_data;

}


uint8_t FXLS8974_Init(fxls_handle_t *fxlsHandle)
{


    fxls_config_t config        = {0};
    uint8_t dataScale       = 0;
    status_t result;
    uint8_t sensorRange     = 0;


    BOARD_I2C_ReleaseBus();
    BOARD_I2C_ConfigurePins();
    /* I2C initialize */
    BOARD_Accel_I2C_Init();

    /* Configure the I2C function */
    config.I2C_SendFunc    = BOARD_Accel_I2C_Send;
    config.I2C_ReceiveFunc = BOARD_Accel_I2C_Receive;
    config.slaveAddress    = g_accel_address;

    /* Initialize sensor devices */
    result = FXLS_Init(fxlsHandle, &config);

    if (result != kStatus_Success)
    {
        PRINTF("\r\nSensor device initialize failed!\r\n");
        return -1;
    }

    /* Get sensor range */
    if (FXLS_ReadReg(fxlsHandle, SENS_CONFIG1_REG, &sensorRange, 1) != kStatus_Success)
    {
        return -1;
    }

    sensorRange = (sensorRange & 0x6) >> 1;

    if (sensorRange == 0x00)
    {
        dataScale = 2U;
        correction=0.000976;

    }
    else if (sensorRange == 0x01)
    {
        dataScale = 4U;
        correction=0.001953;


    }
    else if (sensorRange == 0x10)
    {
        dataScale = 8U;
        correction=0.003906;
    }
    else if (sensorRange == 0x11)
    {
        dataScale = 16U;
        correction=0.007813;
    }
    else
    {
    }

    /* Init timer */
    Timer_Init();

    /* Print a note to terminal */
   // PRINTF("\r\nWelcome to the BUBBLE example\r\n");
  //  PRINTF("\r\nYou will see angle data change in the console when change the angles of board\r\n");

	   /* Main loop. Get sensor data and update duty cycle */
    return dataScale;
}




