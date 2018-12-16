# BluetoothHeater

Bluetooth interface for Chinese Diesel Heaters

Requirements
--------------------------
* Requires "blue wire" compatible heater unit
* Blue wire interface circuitry
* ESP32 dev module
* HC-05 Bluetooth module - preferably exposing the key pin, not power control)
* DS18B20 one wire temperature sensor
* 13.3" I2C OLED using SH1106 controller
* DS3231 Real Time Clock
* Technical ability to solder SMD components
* Technical ability to program/flash in the Arduino environement

Working so far:
--------------------------
* Power On/Off
* Temperature + & -
* Fuel mixture tuning
* One wire remote temperature sensing (DS18B20)
* Heat exchanger body temperature, as reported by heater unit
* I2C Interface to 1.3" SH1106 based OLED for a full featured controller
* 5 button keypad interface
* Smart error detection, observes unusual heater state progression (ignition fail)
* ESP32 with HC-05 Bluetooth
* JSON based communications between Bluetooth and Wifi apps
* Bluetooth Connectivity
* Bluetooth Control App for Android (App Inventor based)
* WiFi Connection to existing network or Standalone Access Point Mode (Passwd: thereisnospoon)
* Wifi control
* DebugPort data sent via Telnet if/when available on the network.
* Two 7 day timers - including repeat every day functionality
* Battery backed Real Time Clock - DS3231
* Prototype "Green PCB" in production, using naked ESP32 and HC-05 modules 

To be implemented 
--------------------------
* MQTT pub/sub 
* Expand hardware compatability with different MCU setups.  IE Arduino Due/Mega/Pro ESP8266 & ESP32
* Documentation
* list under construction.....
