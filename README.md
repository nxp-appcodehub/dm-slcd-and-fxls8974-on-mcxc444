# NXP Application Code Hub
[<img src="https://mcuxpresso.nxp.com/static/icon/nxp-logo-color.svg" width="100"/>](https://www.nxp.com)

## SLCD and FXLS8974 Accelerometer Demo on MCXC444
*This demo uses the on board FXL8974 3-axis Low G accelerometer to obtain real time acceleration data, the on board RGB LED to indicate the orientation, and the SLCD interface prints out the y acceleration data.*




#### Boards: FRDM-MCXC444
#### Categories: HMI, Sensor
#### Peripherals: I2C
#### Toolchains: MCUXpresso IDE

## Table of Contents
1. [Software](#step1)
2. [Hardware](#step2)
3. [Setup](#step3)
4. [Results](#step4)
5. [FAQs](#step5) 
6. [Support](#step6)
7. [Release Notes](#step7)

## 1. Software<a name="step1"></a>
*This software was developed in MCUXpresso IDE, this demo is in baremetal. The application starts when the user powers on the board or starts a debugging session, after that you can see the Red and Blue LEDs will change their brightness depending on the orientation of the FRDM-MCXC444 board. The SLCD interface will also enumerate https://nxp.com/mcuxpresso.*

- [MCUXpresso IDE v11.9.0 or newer.](https://www.nxp.com/design/design-center/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)


## 2. Hardware<a name="step2"></a>
*For this demo you will need the FRDM-MCXC444 board linked below.*

- [MCX C444 FRDM Board.](https://www.nxp.com/design/design-center/development-boards-and-designs/general-purpose-mcus/frdm-development-board-for-mcx-c444-mcus:FRDM-MCXC444)

- Personal Computer
- Mini/micro C USB cable



## 3. Setup<a name="step3"></a>
*After cloning the repository and importing it to the workspace connect the board to the pc using a USB cable in the J13 header.* 

![Alt text](./images/Image.jpg)

*Build and compile the project, debug, then select the target and push play to run the application.*

*Open a serial terminal (RealTerm) with the following settings:*
- 115200 baud rate
- 8 data bits
- No parity
- One stop bit
- No flow control


## 4. Results<a name="step4"></a>
*When the X-axis acceleration is close to 1G, the blue LED will be full brightness. When the Y-Axis acceleration is close to 1G the Red LED will be full brightness. When X and Y axes are at 45 degrees respectively, you will see a pink/purple color, corresponding to both LEDs being on at the same time.*

*The SLCD interface will display the Y axis acceleration in terms of G. When the board is tilted horizontally the SLCD interface will display a value close to 1G. When the board is tilted vertically this number should be close to zero.*

*A serial terminal will additionally print out the values of the X, Y, and Z acceleration data.*


## 5. FAQs
No FAQs have been identified for this project.


## 6. Support<a name="step6"></a>

#### Project Metadata
<!----- Boards ----->
[![Board badge](https://img.shields.io/badge/Board-FRDM&ndash;MCXC444-blue)](https://github.com/search?q=org%3Anxp-appcodehub+FRDM-MCXN947+in%3Areadme&type=Repositories)

<!----- Categories ----->
[![Category badge](https://img.shields.io/badge/Category-HMI-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+hmi+in%3Areadme&type=Repositories) [![Category badge](https://img.shields.io/badge/Category-SENSOR-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+sensor+in%3Areadme&type=Repositories)

<!----- Peripherals ----->
[![Peripheral badge](https://img.shields.io/badge/Peripheral-SLDC-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+dma+in%3Areadme&type=Repositories) [![Peripheral badge](https://img.shields.io/badge/Peripheral-I2C-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+i2c+in%3Areadme&type=Repositories)

<!----- Toolchains ----->
[![Toolchain badge](https://img.shields.io/badge/Toolchain-MCUXPRESSO%20IDE-orange)](https://github.com/search?q=org%3Anxp-appcodehub+mcux+in%3Areadme&type=Repositories)

Questions regarding the content/correctness of this example can be entered as Issues within this GitHub repository.

>**Warning**: For more general technical questions regarding NXP Microcontrollers and the difference in expected funcionality, enter your questions on the [NXP Community Forum](https://community.nxp.com/)

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/@NXP_Semiconductors)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/nxp-semiconductors)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/nxpsemi/)
[![Follow us on Twitter](https://img.shields.io/badge/Twitter-Follow%20us%20on%20Twitter-white.svg)](https://twitter.com/NXP)

## 7. Release Notes<a name="step7"></a>
| Version | Description / Update                           | Date                        |
|:-------:|------------------------------------------------|----------------------------:|
| 1.0     | Initial release on Application Code Hub        | Oct 10 <sup>th</sup> 2024 |