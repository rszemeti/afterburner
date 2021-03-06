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


///////////////////////////////////////////////////////////////////////////
//
// CSettingsScreen
//
// This screen allows the fuel mixture endpoints to be adjusted
//
///////////////////////////////////////////////////////////////////////////

#include "SettingsScreen.h"
#include "KeyPad.h"
#include "../Utility/helpers.h"
#include "../Utility/macros.h"
#include "../Protocol/Protocol.h"
#include "fonts/Arial.h"

static const int Line3 = 20;       // system voltage
static const int Line2 = 30;       // fan sensor
static const int Line1 = 40;       // plug drive
static const int Column = 98;

static const int plugPowers[] = { 35, 40, 45, 80, 85, 90};

CSettingsScreen::CSettingsScreen(C128x64_OLED& display, CScreenManager& mgr) : CPasswordScreen(display, mgr) 
{
  _initUI();
}

void 
CSettingsScreen::onSelect()
{
  // ensure standard entry to screen - especially after a dimming timeout
  CPasswordScreen::onSelect();
  _initUI();
}

bool 
CSettingsScreen::show()
{
  char str[16];
  
//  CScreenHeader::show(false);
//
//  _display.writeFillRect(0, 16, 84, 12, WHITE);
//  _printInverted(3, 18, "Heater Tuning", true);
  CScreen::show();
  _display.clearDisplay();

  _showTitle("Heater Tuning");

  if(!CPasswordScreen::show()) {

    sprintf(str, "%.0fV", getHeaterInfo().getSystemVoltage());
    _printMenuText(_display.width(), Line3, str, false, eRightJustify);

    sprintf(str, "Min: %.1f/%d", getHeaterInfo().getPump_Min(), getHeaterInfo().getFan_Min());
    _printMenuText(0, Line3, str);

    sprintf(str, "Max: %.1f/%d", getHeaterInfo().getPump_Max(), getHeaterInfo().getFan_Max());
    _printMenuText(0, Line2, str);

    int yPos = 53;
    int xPos = _display.xCentre();
    _printMenuText(_display.xCentre(), 53, "                    ", true, eCentreJustify);
    _printMenuText(xPos, yPos, "\030Edit    Exit", false, eCentreJustify);
  }
  
  return true;
}

bool 
CSettingsScreen::animate()
{ 
  if(CScreen::animate())
    return true;

  char msg[16];

  if(isPasswordBusy()) {  // Password screen activity
    _printMenuText(Column, Line1, "    ");
    _printMenuText(Column, Line2, "    ");
  }
  else {
    _animateCount++;
    WRAPUPPERLIMIT(_animateCount, 9, 0);

    int glowDrive = getHeaterInfo().getGlow_Drive();
    _printMenuText(Column, Line1, "     ");
    if(_animateCount < 4) {
      sprintf(msg, "PF-%d", glowDrive);
      _printMenuText(Column+6, Line1, msg);
    }
    else {
      sprintf(msg, "(%dW)", plugPowers[glowDrive-1]);
      _printMenuText(Column, Line1, msg);
    }

    int fanSensor = getHeaterInfo().getFan_Sensor();
    if(_animateCount < 4) {
      sprintf(msg, "SN-%d", fanSensor);
      _printMenuText(Column+6, Line2, msg);
    }
    else {
      int xPos = Column+6;
      _printMenuText(xPos, Line2, "    "); // erase
      sprintf(msg, "(\365%d)", fanSensor);   // \365 is division character
      _printMenuText(xPos, Line2, msg);
    }

  }
  return true;
}

bool 
CSettingsScreen::keyHandler(uint8_t event)
{
  if(CPasswordScreen::keyHandler(event)) {  // handles password collection 
    if(_isPasswordOK()) {
      _ScreenManager.selectMenu(CScreenManager::TuningMenuLoop);
    }
    return true;
  }

  if(event & keyPressed) {
    // press LEFT 
    if(event & key_Left) {
      _ScreenManager.selectMenu(CScreenManager::RootMenuLoop);
    }
    // press RIGHT 
    if(event & key_Right) {
      _ScreenManager.selectMenu(CScreenManager::RootMenuLoop);
    }
    // press UP 
    if(event & key_Up) {
      if(hasOEMcontroller()) {
        if(event & key_Centre)
          _reqOEMWarning();
        else {
          _ScreenManager.selectMenu(CScreenManager::BranchMenu, CScreenManager::InheritSettingsUI);
        }
      }
      else {
        _getPassword();
        if(_isPasswordOK()) {
          _ScreenManager.selectMenu(CScreenManager::TuningMenuLoop);
        }
      }
    }
    if(event & key_Centre) {
      _ScreenManager.selectMenu(CScreenManager::RootMenuLoop);
    }
    // press DOWN
    if(event & key_Down) {
      _ScreenManager.selectMenu(CScreenManager::RootMenuLoop);
//        _ScreenManager.selectMenu(CScreenManager::BranchMenu, CScreenManager::ExperimentalUI);
//        _ScreenManager.selectMenu(CScreenManager::UserSettingsLoop, CScreenManager::ExThermostatUI);
    }
    // THREE FINGER SALUTE!
    if((event & (key_Left|key_Right|key_Centre)) == (key_Left|key_Right|key_Centre)) {
      for(;;);  // force watchdog reboot!
    }
  }

  _ScreenManager.reqUpdate();
  return true;
}

