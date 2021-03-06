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

#ifndef __SCREEN_MANAGER_H__
#define __SCREEN_MANAGER_H__

#include <vector>
#include "../Utility/UtilClasses.h"

class C128x64_OLED;
class CScreen;
class CRebootScreen;

class CScreenManager {
  std::vector<std::vector<CScreen*>> _Screens;
  CRebootScreen* _pRebootScreen;
  C128x64_OLED* _pDisplay;
  unsigned long _OTAholdoff;
  int _menu;
  int _subMenu;
  int _rootMenu;
  int _returnMenu;
  int _returnSubMenu;
  bool _bDimmed;
  bool _bReload;
  unsigned long _DimTime_ms;
  unsigned long _MenuTimeout;
  bool _bReqUpdate;
  void _enterScreen();
  void _leaveScreen();
  void _changeSubMenu(int dir);
  void _dim(bool state);
  void _loadScreens();
  void _unloadScreens();
  bool _checkOTAholdoff();
public:
  enum eUIMenuSets { RootMenuLoop, TimerMenuLoop, UserSettingsLoop, SystemSettingsLoop, TuningMenuLoop, BranchMenu };
  enum eUIRootMenus { DetailedControlUI, BasicControlUI, ClockUI, ModeUI, GPIOInfoUI, TrunkUI };
  enum eUITimerMenus { TimerOverviewUI, Timer1UI, Timer2UI, Timer3UI, Timer4UI, Timer5UI, Timer6UI, Timer7UI,
                       Timer8UI, Timer9UI, Timer10UI, Timer11UI, Timer12UI, Timer13UI, Timer14UI };
  enum eUITuningMenus { MixtureUI, HeaterSettingsUI, FuelCalUI };
  enum eUIUserSettingsMenus { ExThermostatUI, FrostUI, HomeMenuUI, TimeIntervalsUI, TempSensorUI, GPIOUI };
  enum eUIBranchMenus { SetClockUI, InheritSettingsUI, HtrSettingsUI, DS18B20UI };
  enum eUISystemSettingsMenus { SysVerUI, SysHoursUI, SysWifiUI, SysBTUI };
public:
  CScreenManager();
  ~CScreenManager();
  void begin();
  bool checkUpdate();
  bool animate();
  void keyHandler(uint8_t event);
  void refresh();
  void nextMenu();
  void prevMenu();
  void reqUpdate();
  void selectHomeMenu();
  void selectMenu(eUIMenuSets menuset, int specific = -1);   // use to select loop menus, including the root or branches
  void returnMenu();   // use to select loop menus, including the root or branches
  void showRebootMsg(const char* content[2], long delayTime);
  void showBootMsg(const char* msg);
  void showBootWait(int show);
  void showOTAMessage(int percent, eOTAmodes updateType);
  void clearDisplay();
  void bumpTimeout();
  void showSplash();
  void reqReload() { _bReload = true; };
};

#endif // __SCREEN_MANAGER_H__
