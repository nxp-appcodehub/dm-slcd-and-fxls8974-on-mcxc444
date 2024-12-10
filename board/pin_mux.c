/*
* Copyright 2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/
 

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v16.0
processor: MCXC444
package_id: MCXC444VLH
mcu_data: ksdk2_0
processor_version: 16.1.0
external_user_signals: {}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: LPUART0, signal: RX, pin_signal: PTA1/LPUART0_RX/TPM2_CH0}
  - {pin_num: '24', peripheral: LPUART0, signal: TX, pin_signal: PTA2/LPUART0_TX/TPM2_CH1}
  - {pin_num: '9', peripheral: LCD, signal: 'P, 59', pin_signal: LCD_P59/ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/LPUART0_TX/FXIO0_D4}
  - {pin_num: '10', peripheral: LCD, signal: 'P, 60', pin_signal: LCD_P60/ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/LPUART0_RX/FXIO0_D5}
  - {pin_num: '41', peripheral: LCD, signal: 'P, 14', pin_signal: LCD_P14/PTB18/TPM2_CH0/I2S0_TX_BCLK}
  - {pin_num: '42', peripheral: LCD, signal: 'P, 15', pin_signal: LCD_P15/PTB19/TPM2_CH1/I2S0_TX_FS}
  - {pin_num: '43', peripheral: LCD, signal: 'P, 20', pin_signal: LCD_P20/ADC0_SE14/PTC0/EXTRG_IN/USB_SOF_OUT/CMP0_OUT/I2S0_TXD0}
  - {pin_num: '53', peripheral: LCD, signal: 'P, 24', pin_signal: LCD_P24/PTC4/LLWU_P8/SPI0_SS/LPUART1_TX/TPM0_CH3/I2S0_MCLK}
  - {pin_num: '55', peripheral: LCD, signal: 'P, 26', pin_signal: LCD_P26/CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/I2S0_RX_BCLK/SPI0_MISO/I2S0_MCLK}
  - {pin_num: '56', peripheral: LCD, signal: 'P, 27', pin_signal: LCD_P27/CMP0_IN1/PTC7/SPI0_MISO/USB_SOF_OUT/I2S0_RX_FS/SPI0_MOSI}
  - {pin_num: '57', peripheral: LCD, signal: 'P, 40', pin_signal: LCD_P40/PTD0/SPI0_SS/TPM0_CH0/FXIO0_D0}
  - {pin_num: '59', peripheral: LCD, signal: 'P, 42', pin_signal: LCD_P42/PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO/FXIO0_D2}
  - {pin_num: '60', peripheral: LCD, signal: 'P, 43', pin_signal: LCD_P43/PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI/FXIO0_D3}
  - {pin_num: '61', peripheral: LCD, signal: 'P, 44', pin_signal: LCD_P44/PTD4/LLWU_P14/SPI1_SS/UART2_RX/TPM0_CH4/FXIO0_D4}
  - {pin_num: '16', peripheral: ADC0, signal: VALTL, pin_signal: VSSA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTA1 (pin 23) is configured as LPUART0_RX */
    PORT_SetPinMux(PORTA, 1U, kPORT_MuxAlt2);

    /* PORTA2 (pin 24) is configured as LPUART0_TX */
    PORT_SetPinMux(PORTA, 2U, kPORT_MuxAlt2);

    /* PORTB18 (pin 41) is configured as LCD_P14 */
    PORT_SetPinMux(PORTB, 18U, kPORT_PinDisabledOrAnalog);

    /* PORTB19 (pin 42) is configured as LCD_P15 */
    PORT_SetPinMux(PORTB, 19U, kPORT_PinDisabledOrAnalog);

    /* PORTC0 (pin 43) is configured as LCD_P20 */
    PORT_SetPinMux(PORTC, 0U, kPORT_PinDisabledOrAnalog);

    /* PORTC4 (pin 53) is configured as LCD_P24 */
    PORT_SetPinMux(PORTC, 4U, kPORT_PinDisabledOrAnalog);

    /* PORTC6 (pin 55) is configured as LCD_P26 */
    PORT_SetPinMux(PORTC, 6U, kPORT_PinDisabledOrAnalog);

    /* PORTC7 (pin 56) is configured as LCD_P27 */
    PORT_SetPinMux(PORTC, 7U, kPORT_PinDisabledOrAnalog);

    /* PORTD0 (pin 57) is configured as LCD_P40 */
    PORT_SetPinMux(PORTD, 0U, kPORT_PinDisabledOrAnalog);

    /* PORTD2 (pin 59) is configured as LCD_P42 */
    PORT_SetPinMux(PORTD, 2U, kPORT_PinDisabledOrAnalog);

    /* PORTD3 (pin 60) is configured as LCD_P43 */
    PORT_SetPinMux(PORTD, 3U, kPORT_PinDisabledOrAnalog);

    /* PORTD4 (pin 61) is configured as LCD_P44 */
    PORT_SetPinMux(PORTD, 4U, kPORT_PinDisabledOrAnalog);

    /* PORTE20 (pin 9) is configured as LCD_P59 */
    PORT_SetPinMux(PORTE, 20U, kPORT_PinDisabledOrAnalog);

    /* PORTE21 (pin 10) is configured as LCD_P60 */
    PORT_SetPinMux(PORTE, 21U, kPORT_PinDisabledOrAnalog);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK)))

                  /* LPUART0 Transmit Data Source Select: LPUART0_TX pin. */
                  | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX)

                  /* LPUART0 Receive Data Source Select: LPUART_RX pin. */
                  | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX));


    /* PORTD5 (pin 62) is configured as TPM0_CH5 */
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAlt4);

    /* PORTE31 (pin 19) is configured as TPM0_CH4 */
    PORT_SetPinMux(PORTE, 31U, kPORT_MuxAlt3);

    /* PORTE29 (pin 17) is configured as TPM0_CH2 */
    PORT_SetPinMux(PORTE, 29U, kPORT_MuxAlt3);



}
void BOARD_I2C_ConfigurePins(void)
{
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t gpiod_pin58_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD1 (pin 58)  */
    GPIO_PinInit(GPIOD, 1U, &gpiod_pin58_config);

    /* PORTD1 (pin 58) is configured as PTD1 */
    PORT_SetPinMux(PORTD, 1U, kPORT_MuxAsGpio);

    const port_pin_config_t porte24_pin20_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as I2C0_SCL */
                                                    kPORT_MuxAlt5};
    /* PORTE24 (pin 20) is configured as I2C0_SCL */
    PORT_SetPinConfig(PORTE, 24U, &porte24_pin20_config);

    const port_pin_config_t porte25_pin21_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as I2C0_SDA */
                                                    kPORT_MuxAlt5};
    /* PORTE25 (pin 21) is configured as I2C0_SDA */
    PORT_SetPinConfig(PORTE, 25U, &porte25_pin21_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
