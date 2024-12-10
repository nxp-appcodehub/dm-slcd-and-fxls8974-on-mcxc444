Overview
========

The SLCD example shows how to use SLCD driver.

SDK version
===========
- Version: 2.16.000

Toolchain supported
===================
- IAR embedded Workbench  9.60.1
- Keil MDK  5.39.0
- GCC ARM Embedded  13.2.1
- MCUXpresso  11.10.0

Hardware requirements
=====================
- Type-C USB cable
- FRDM-MCXC444 board
- Personal Computer

Board settings
==============
No special jumper settings

Prepare the Demo
================
1. Connect a type-c USB cable between the host PC and the MCU-Link USB port (J13) on the target board.
2. Open a serial terminal with these settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================

In this example, the SLCD displays as below.
1. Show digital numbers.
2. Show the icons one by one.
3. All segments on, blink, then turn off.