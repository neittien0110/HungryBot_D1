# Hungry Bot Recycle Bin

 ![Introduce Hungry Bot](./images/HungryBotShield.jpg)

## Overview

- This source code used for [Wemos Lolin D1 R2 mni](https://neittien0110.github.io/MCU/ESP8266/Wemosd1r2mini.html)\
  ![D1 R2 mini](https://neittien0110.github.io/MCU/assets/esp8266_wemosd1r2mini_ledbuiltin.png)\
  [Xem hướng dẫn](https://neittien0110.github.io/MCU/ESP8266/Wemosd1r2mini.html)

## Video

- [Demo](https://youtu.be/PHz48JWzXpA)

## Bill of Material

|Name|Qty|Mapping| Code |
|----|----|----|----|
|Wemos D1 R2 mini | 1 (*) |  |  |
|Servo SG90s | 1 (*) | D3 (or GPIO0) | #define PIN_SERVOHAND = D3 |
|Ultrasonic Distance Sensor SR-04 | 1 (*) |ECHO = D2 (or GPIO4) <br/> TRIG = D1 (or GPIO5) | #define PIN_ECHO D2 <br/> #define PIN_TRIG D1 |
|Led 5mm | 1 | D1 (or GPIO5) | #define PIN_LED = D1 |

- [3D printed parts](https://www.thingiverse.com/thing:5160440)

*: mandatory

## HungryBotShield

![HungryBotShield real](https://image.easyeda.com/pullimage/bRcvGseW6uTdBQ1zP42PAcZSu7V20llFNgRsNlmf.jpeg)
[HungryBotShield Schematic and PCB](https://oshwlab.com/neittien0110/hungryboardshield)

### How to assembly

1. A shield \
  ![Connect to servo](./images/HungryBotShield_Free.jpg)
1. Connect to servo.\
   ![Connect to servo](./images/HungryBotShield_Servo.jpg)
1. Connect to HC-04.\
   ![Connect to HC-04](./images/HungryBotShield_HC04.jpg)
1. Connect to button/dip switch.\
   ![Connect to HC-04](./images/HungryBotShield_Button.jpg)
1. Connect to battery.\
   ![Connect to HC-04](./images/HungryBotShield_Battery.jpg)
1. Connect to Micro Processor - Wemos D1 R2 mini.\
   ![Connect to MCU](./images/HungryBotShield_MCU.jpg)
1. Already\
    ![Connect to MCU](./images/HungryBotShield_All.jpg)
    ![Connect to MCU](./images/HungryBotShield_All2.jpg)
