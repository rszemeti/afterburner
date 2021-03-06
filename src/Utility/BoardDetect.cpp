/*
 * This file is part of the "bluetoothheater" distribution 
 * (https://gitlab.com/mrjones.id.au/bluetoothheater) 
 *
 * Copyright (C) 2018  Ray Jones <ray@mrjones.id.au>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 */

//
// We need to identify the PCB the firmware is running upon for 2 reasons related to GPIO functions
//
// 1: Digital Inputs
//    To the outside world, the digital inputs are always treated as contact closures to ground.
//    V1.0 PCBs expose the bare ESP inputs for GPIO, they are normally pulled HIGH.
//    V2.0+ PCBs use an input conditioning transistor that inverts the sense state.
//      Inactive state for V1.0 is HIGH
//      Inactive state for V2.0+ is LOW
//
// 2: Analogue input
//    Unfortunately the pin originally chosen for the analogue input on the V2.0 PCB goes to 
//    an ADC2 channel of the ESP32.
//    It turns out NONE of the 10 ADC2 channels can be used if Wifi is enabled!
//    The remedy on V2.0 PCBs is to cut the traces leading from Digital input 1 and the Analogue input.
//    The signals are then tranposed.
//    This then presents Digital Input #1 to GPIO26, and analogue to GPIO33.
//    As GPIO33 uses an ADC1 channel no issue is present reading analogue values with wifi enabled.
//
//  Board Detection
//    Fortunately due to the use of the digital input transistors on V2.0+ PCBs, a logical
//    determination of the board configuration can be made.
//    By setting the pins as digital inputs with pull ups enabled, the logic level presented
//    can be read and thus the input signal paths can be determined.
//    Due to the input conditioning transistors, V2.0 PCBs will hold the inputs to the ESP32 
//    LOW when inactive, V1.0 PCBs will pull HIGH.
//    Likewise, the analogue input is left to float, so it will always be pulled HIGH.
//    NOTE: a 100nF capacitor exists on the analogue input so a delay is required to ensure
//    a reliable read.
//
//  Input state truth table
//                        GPIO25    GPIO26    GPIO33
//                        ------    ------    ------
//                 V1.0    HIGH      HIGH      HIGH    - green V1 PCB
//      unmodified V2.0    LOW       HIGH      LOW     - digital only (V2 PCB)
//      modified   V2.0    LOW       LOW       HIGH    - full GPIO (V2 or V3 PCB)
//                 V2.1    LOW       LOW       HIGH    - digital only (modified V2 PCB)
//         No GPIO V2.0    HIGH      LOW       HIGH    - no GPIO (V2 PCB, 0R in C6) 
//                 V2.1    LOW       LOW       LOW     - digital only (V3 PCB, 0R in C6)
//         No GPIO V3.x    HIGH      HIGH      LOW     - no GPIO (V3.x PCB, 0R in C6)
//
//
//  ****************************************************************************************
//  This test only needs to be performed upon the very first firmware execution.
//  Once the board has been identified, the result is saved to non volatile memory 
//  If a valid value is detected, the test is bypassed.
//  This avoids future issues should the GPIO inputs be legitimately connected to 
//  extension hardware that may distort the test results when the system is repowered.
//  ****************************************************************************************
// 

#include "BoardDetect.h"
#include <Preferences.h>
#include <driver/adc.h>
#include "DebugPort.h"

void BoardRevisionReset()
{
  Preferences preferences;

  preferences.begin("System Info", false);
  preferences.clear();
}

int BoardDetect()
{
  Preferences preferences;

  preferences.begin("System Info", false);

  uint8_t revision = 0;
  uint8_t val = preferences.getUChar("Board Revision", revision);
  if(val != 0) {
    DebugPort.printf("Board detect: Using saved revision V%.1f\r\n", float(val) * 0.1f);
    return val;
  }
  
  DebugPort.println("Board detect: Virgin system - attempting to detect revision");
  pinMode(25, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  // there is a 100nF capacitor across the analogue input, allow that to charge before testing
  delay(100);   
  int pin25 = digitalRead(25);
  int pin33 = digitalRead(33);   
  int pin26 = digitalRead(26);

  // all pins to header strip and pulled high - V1 PCB
  if((pin33 == HIGH) && (pin26 == HIGH) && (pin25 == HIGH)) {   
    revision = BRD_V1_FULLGPIO;
    DebugPort.println("Board detect: digital input test reveals V1.x PCB");
  }
  // original V2 PCB, no traces cut n shunted, unusable Alg to pin 26 pulls high, dig inputs pulled low by transistors
  else if((pin33 == LOW) && (pin26 == HIGH) && (pin25 == LOW)) {  
    revision = BRD_V2_GPIO_NOALG;
    DebugPort.println("Board detect: digital input test reveals V2.0 PCB - Digital only GPIO (V2.1 userID)");
  }
  // V3 PCB, no traces cut n shunted, pin 26 grounded via 0R instead of 100n cap, dig inputs pulled low by transistors
  else if((pin33 == LOW) && (pin26 == LOW) && (pin25 == LOW)) {  
    revision = BRD_V3_GPIO_NOALG;
    DebugPort.println("Board detect: digital input test reveals V3.0 PCB - Digital only GPIO (V2.1 userID)");
  }
  // original V2 PCB, pin 26 grounded via 0R instead of 100n cap, digio transistors not fitted dig in pins pull high
  else if((pin33 == HIGH) && (pin26 == LOW) && (pin25 == HIGH)) {  
    revision = BRD_V2_NOGPIO;
    DebugPort.println("Board detect: digital input test reveals V2.2 PCB - no GPIO (V2.0 userID) ");
  }
  // V3.x PCB, pin 33 grounded via 0R instead of 100n cap, digio transistors not fitted dig in pins pull high
  else if((pin33 == LOW) && (pin26 == HIGH) && (pin25 == HIGH)) {  
    revision = BRD_V2_NOGPIO;
    DebugPort.println("Board detect: digital input test reveals V3.x PCB - no GPIO (V2.0 userID) ");
  }
  // modified V2 PCB or new V2.1PCB, pins 25 & 33 swapped, Alg routed to usuable pin 33 // cap, dig inputs pulled low by transistors
  else if((pin33 == HIGH) && (pin26 == LOW) && (pin25 == LOW)) {   
    revision = BRD_V2_FULLGPIO;
    DebugPort.println("Board detect: digital input test reveals V2.1 PCB - Full GPIO (V2.2 userID)");
  }
  else {
    DebugPort.println("Board detect: digital input test failed to detect a valid combination!!!");
  }

  pinMode(33, INPUT);  // revert to normal inputs (remove pull ups)
  pinMode(26, INPUT);
  pinMode(25, INPUT);  // revert to normal inputs (remove pull ups)

  //store the detected revision
  if(revision) {
    preferences.putUChar("Board Revision", revision);
  }

  DebugPort.printf("Board detect: Result = V%.1f\r\n", float(revision)*0.1f);
  return revision;
}

const char* getBoardRevisionString(int ID)
{
  switch(ID) {
    case BRD_V1_FULLGPIO: return "V1.0"; 
    case BRD_V2_FULLGPIO: return "V2.2"; 
    case BRD_V2_NOGPIO: return "V2.0"; 
    case BRD_V2_GPIO_NOALG: return "V2.1"; 
    case BRD_V3_GPIO_NOALG: return "V2.1"; 
    default: return "???"; 
  }
}
