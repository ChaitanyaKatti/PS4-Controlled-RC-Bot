# PS4-Controlled-RC-Bot
Using a Bluetooth capable microcontroller and PS4 to drive a RC car.


# Making The Bot

## Mechanical & Electrical Parts
The bot was bulit using hand cut 3mm acryllic sheets. 4 DC 200rpm motors are mounted on the bottom side with 7x4cm wheels.

For electronics, I've used 
1. ESP32 microcontroller.
2. L298N motor driver, with PWM to controller the speed of motors.
3. LM2596 Buck converter, to provide 5V for the ESP32.
4. 12V battery, to power the whole thing.

## The Code
The bot can also be controlled using [wifi](https://erc-iitb.notion.site/XLR8-Resources-27b1a2116f954aae86102328ae5c1657).

But a connection over Bluetooth is far more reliable and PS4 controller has very low latency and good range.

This project uses arduino IDE to write and flash code onto ESP32 microcontroller.
The code uses the library https://github.com/aed3/PS4-esp32.

Follow [this](https://erc-iitb.notion.site/XLR8-Resources-27b1a2116f954aae86102328ae5c1657) notion webpage for installation and setup for coding environment.

Once you've ready to code, download and add the [PS4-esp32.zip](https://github.com/aed3/PS4-esp32/archive/refs/heads/master.zip) library to the adruino IDE.

## Features
The code enable the driver to access two mode. 
1. Button Mode - The square, triangle, circle and X buttons on the PS4 to move the bot forward, back, left and right. While simultaneously controlling the PWM(overall speed) of the all motors using the variable analog trigger L2. This allows to turn and accerelerate with presicion.
2. Joystick Mode - In this, both the left and right analog stick are used to move the bot. Each stick controller the speed of the motor on that side on the bot. It is like tank steering with individual access to both sides.

By pressing the PS Touchpad, the modes can be swithced back and forth.

There is also a bumper sensor in the front of the car that can sense the frontal collision of bot and send sigal to esp32 through which the driver is notified by the vibration of the PS controller.


