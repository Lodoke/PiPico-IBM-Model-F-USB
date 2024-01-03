# PiPico-IBM-Model-F-USB
A fairly simple program for the Raspberry Pi Pico that connects to an IBM Model F XT and relays keypresses to the USB Host (Your PC)

NOTE: I live in the UK so the keymap is for a <b>UK LAYOUT</b> if you want a US layout then tough.

# User Guide
 - Connect the Clock Pin to that defined in the CLK macro (default 27)
 - Connect the Data Pin to that defined in DAT macro (default 28)
 - Connect the keyboards +5v pin to the vsys pin on the pico
 - Connect the ground pin to any GND pin on the pico
 - Open the .ino file in the Arduino IDE install the rp2040 mbed os boards through the boards manager
 - Plug in the keyboard into the Pico and the Pico into the computer
 - Select the Raspberry Pi Pico in the Arduino IDE
 - Press the program button in the top left corner (Big Arrow)
 - Congratulations! You should have a functional Model F XT -> USB adapter

The Pico can be external to the keyboard and use a DIN connector to interface with the original cable,
or it can be mounted internally to the keyboard.

This code also supports another keymap layer, accessed by the scroll lock key, at present it only maps F11 -> F20 to the function keys
