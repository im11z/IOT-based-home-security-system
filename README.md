# IoT Based Home Security System

## Overview
This project implements an IoT-based home security system using Arduino and multiple sensors.
It detects gas leakage, fire (temperature rise), unauthorized intrusion, and abnormal light
activity, and sends real-time alerts to the user through the internet.

## Features
- Gas leakage detection
- Temperature (fire) detection
- Intruder detection using IR sensors
- Light-based intrusion detection
- Real-time alerts via IoT (Blynk)
- Remote monitoring using smartphone

## Hardware Components
- Arduino Uno
- ESP8266 WiFi Module
- Gas Sensor (MQ/TGS series)
- LM35 Temperature Sensor
- LDR
- IR Sensor
- LCD 16x2
- IC 555, LM324, LM567
- Power Supply

## Software Used
- Arduino IDE
- Embedded C / C++
- Blynk IoT Platform

## System Architecture
Sensors collect data → Arduino processes data → ESP8266 sends data → Cloud → Mobile App alerts

## Applications
- Smart homes
- Gas leakage monitoring
- Fire detection systems
- Home intrusion detection

## Author
Final Year Major Project
