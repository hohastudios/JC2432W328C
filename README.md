# JC2432W328C 2.8" ESP32 Display Sample Code

This repository contains simple example sketches for the **2.8" ESP32 Display JC2432W328C**, a 240x320 TFT LCD module with capacitive touch. It's based on the **ST7789** driver and uses the **ESP32** microcontroller, compatible with the **Arduino IDE**.

> 📦 Available here on Amazon: [https://amzn.to/46hr7PK](https://amzn.to/46hr7PK)

---

## 🔧 Hardware Overview

- **Model:** JC2432W328C
- **Screen:** 2.8" TFT LCD (240x320 resolution)
- **Touch:** Capacitive Touchscreen
- **Controller:** ST7789
- **MCU:** Built-in ESP32
- **Backlight:** GPIO 27 (active HIGH)

---

## 📁 Included Samples

### 1. Basic Board Test
Just to make sure you can connect and communicate - It shows the built in RGB rotate through colors on the board.


### 2. LCD Screen Test
This test uses the LovyanGFX library to display colored circles and a “Display OK” message.


[Watch the demo on YouTube](https://youtu.be/Q_S0smJb_ac)

### 3. Capacitive Touch
This test also uses the LovyanGFX library to interact with the CST820 Capacitive Touchscreen Driver and as you touch will draw circles on the screen.
