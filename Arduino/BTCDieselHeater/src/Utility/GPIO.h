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

#ifndef __BTCGPIO_H__
#define __BTCGPIO_H__

#include <stdint.h>
#include <driver/adc.h>
#include "Debounce.h"

enum GPIOinModes { 
  GPIOinNone, 
  GPIOinOn1Off2,   // input 1 closure, heater starts; input2 closure, heater stops
  GPIOinOnHold1,   // hold input 1 closure, heater runs; input 1 open, heater stops
  GPIOinOn1Off1    // alternate input 1 closures start or stop the heater 
};

enum GPIOoutModes { 
  GPIOoutNone, 
  GPIOoutStatus,
  GPIOoutUser
};

enum GPIOalgModes {
  GPIOalgNone,   // Unmodified V2.0 PCBs must use this - ADC2 / Wifi unresolvable conflict
  GPIOalgHeatDemand,
};


class CGPIOin {
  GPIOinModes _Mode;
  CDebounce _Debounce;
//  int _pinActive;
//  int _pins[2];
//  uint8_t _prevPins;
//  uint8_t _debouncedPins;
  uint8_t _lastKey;
//  unsigned long _lastDebounceTime;
//  unsigned long _debounceDelay;
//  uint8_t _scanInputs();
  void _doOn1Off2();
  void _doOnHold1();
  void _doOn1Off1();
public:
  CGPIOin();
  void setMode(GPIOinModes mode) { _Mode = mode; };
  void begin(int pin1, int pin2, GPIOinModes mode, int activeState);
  void manage();
  uint8_t getState(int channel);
};

class CGPIOout {
  GPIOoutModes _Mode;
  void _doStatus();
  void _doUser();
  int _pins[2];
  int _prevState;
  int _statusState;
  int _statusDelay;
  unsigned long _breatheDelay;
  uint8_t _userState;
  void _doStartMode();
  void _doStopMode();
  void _doSuspendMode();
public:
  CGPIOout();
  void setMode(GPIOoutModes mode);
  void begin(int pin1, int pin2, GPIOoutModes mode);
  void manage();
  void setState(int channel, bool state);
  bool getState(int channel);
};

class CGPIOalg {
  GPIOalgModes _Mode;
  float _expMean;
  adc1_channel_t _pin;
public:
  CGPIOalg();
  void begin(adc1_channel_t pin, GPIOalgModes mode);
  void manage();
  int getValue();
};


#endif // __BTCGPIO_H__