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

