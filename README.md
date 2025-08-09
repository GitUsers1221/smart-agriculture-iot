# smart-agriculture-iot

A low-cost IoT system for monitoring temperature, humidity, and soil moisture in agricultural setups using DHT22 sensors, soil moisture probes, and an Arduino/ESP8266.

## 🚀 Features
- Real-time temperature & humidity monitoring (3 DHT22 sensors)
- Multi-point soil moisture sensing
- Support for multiplexing multiple analog sensors
- Serial output for PC monitoring 
- Expandable for Wi-Fi / cloud integration

## 🛠 Hardware Used
- ESP32 board
- DHT22 sensors × 3
- Soil moisture sensors × 3 (HW-080)
- Multiplexer or manual switching for analog pins
- Jumper wires, breadboard

## 📦 Folder Structure
- `arduino_code/` → Arduino `.ino` file
- `docs/` → Wiring diagram, screenshots

## ⚙️ How to Run
1. Upload `.ino` file to your /ESP32.
2. Open Serial Monitor at 115200 baud.
