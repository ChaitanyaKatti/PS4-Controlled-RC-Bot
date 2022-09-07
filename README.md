# PS4-Controlled-RC-Bot
Using a Bluetooth capable microcontroller and PS4 to drive a RC car.
This project uses arduino IDE to write and flash code onto ESP32 microcontroller.
The code uses the library https://github.com/aed3/PS4-esp32

# Making The Bot

## Mechanical & Electrical Parts
The bot was bulit using hand cut 3mm acryllic sheets. 4 DC 200rpm motors are mounted on the bottom side with 7x4cm wheels.

For electronics, I've used 
1. ESP32 microcontroller.
2. L298N motor driver, with PWM to controller the speed of motors.
3. LM2596 Buck converter, to provide 5V for the ESP32.
4. 12V battery, to power the whole thing.

