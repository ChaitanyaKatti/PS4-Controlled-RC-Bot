# PS4-Controlled-RC-Bot
Using a Bluetooth capable microcontroller and PS4 to drive a RC car.


# Making The Bot

## Mechanical Parts
The bot was bulit using hand cut 3mm acryllic sheets. 4 DC 200rpm motors are mounted on the bottom side with 7x4cm wheels.

The motors on each side run simultaneously kinda like tank steering.

I've used differetnial trottle to steer the bot left right as well as rotate at a fixed point.

## Electorincs Part
For electronics, I've used 
1. ESP32 microcontroller.
2. L298N motor driver, with PWM to controller the speed of motors.
3. LM2596 Buck converter, to provide 5V for the ESP32.
4. 12V battery, to power the whole thing.

Click here for [circuit diagram](https://drive.google.com/file/d/1twA_VGiNjjAlo-SBfk5Sl7oSNgCqTR_O/view?usp=sharing)

## The Code
The bot can also be controlled using [wifi](https://erc-iitb.notion.site/XLR8-Resources-27b1a2116f954aae86102328ae5c1657).
But a connection over Bluetooth is far more reliable and PS4 controller has very low latency and good range.

This project uses arduino IDE to write and flash code onto ESP32 microcontroller.
The code uses the library https://github.com/aed3/PS4-esp32.

Follow [this](https://erc-iitb.notion.site/XLR8-Resources-27b1a2116f954aae86102328ae5c1657) notion webpage for installation and setup for coding environment.

Once you've ready to code, download and add the [PS4-esp32.zip](https://github.com/aed3/PS4-esp32/archive/refs/heads/master.zip) library to the adruino IDE.

## Setting Up Your Controller
First of all you need a PS4 controller. Download [SixAxis Pair Tool](https://sixaxispairtool.en.lo4d.com/windows).

Now connect your controller using a usb mini cable(the same cable used to flash esp32) to laptop and launch Six Axis Pair Tool.
Here you can change the MAC address stored inside of your controller which let you connect with esp32 seamlessly.
Be sure to put the same MAC address in the Arduino code before flashing.


# Features
The code enable the driver to access two mode. 
1. Button Mode - The square, triangle, circle and X buttons on the PS4 to move the bot forward, back, left and right. While simultaneously controlling the PWM(overall speed) of the all motors using the variable analog trigger L2. This allows to turn and accerelerate with presicion.
2. Joystick Mode - In this, both the left and right analog stick are used to move the bot. Each stick controller the speed of the motor on that side on the bot. It is like tank steering with individual access to both sides.

By pressing the PS Touchpad, the modes can be swithced back and forth.

There is also a bumper sensor in the front of the car that can sense the frontal collision of bot and send sigal to esp32 through which the driver is notified by the vibration of the PS controller.

<p align="center">
  <img width="320" height="200" src="https://s4.gifyu.com/images/ezgif-3-ad8b9226cc.gif">
  <img src="https://s4.gifyu.com/images/PS439a4ef8b26294286.gif" width="320" height="200">
</p>
