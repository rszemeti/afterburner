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

#include "128x64OLED.h"
#include "HeaterSettingsScreen.h"
#include "FuelCalScreen.h"
#include "KeyPad.h"
#include "../Utility/helpers.h"
#include "../Utility/macros.h"
#include "../Utility/NVStorage.h"
#include "../Protocol/Protocol.h"

///////////////////////////////////////////////////////////////////////////
//
// CHeaterSettingsScreen
//
// This screen provides a basic control function
//
///////////////////////////////////////////////////////////////////////////

static const int Line3 = 14;
static const int Line2 = 27;
static const int Line1 = 40;
static const int Column = 96;

static const int plugPowers[] = { 35, 40, 45, 80, 85, 90};

CHeaterSettingsScreen::CHeaterSettingsScreen(C128x64_OLED& display, CScreenManager& mgr) : CPasswordScreen(display, mgr) 
{
  _initUI();
  _fanSensor = 1;
  _glowDrive = 5;
  _sysVoltage = 12;
}

void 
CHeaterSettingsScreen::onSelect()
{
  CPasswordScreen::onSelect();
  _initUI();
  _fanSensor = NVstore.getHeaterTuning().fanSensor; 
  _glowDrive = NVstore.getHeaterTuning().glowDrive; 
  _sysVoltage = NVstore.getHeaterTuning().sysVoltage / 10; 
}

bool 
CHeaterSettingsScreen::show()
{
  char msg[20];
  _display.clearDisplay();

  if(!CPasswordScreen::show()) {  // for showing "saving settings"

    _showTitle("Heater Settings");
    _printMenuText(97, Line3, "System voltage:", false, eRightJustify);
    _printMenuText(97, Line2, "Fan sensor:", false, eRightJustify);
    _printMenuText(97, Line1, "Glowplug power:", false, eRightJustify);
    sprintf(msg, "%dV", _sysVoltage);
    _printMenuText(Column, Line3, msg, _rowSel == 3);
    // navigation line
    int yPos = 53;
    int xPos = _display.xCentre();

    switch(_rowSel) {
      case 0:
        _printMenuText(xPos, yPos, " \021     Exit     \020 ", true, eCentreJustify);
        break;
      default:
        _display.drawFastHLine(0, 52, 128, WHITE);
        _printMenuText(xPos, 56, "\030\031Sel          \033\032 Adj", false, eCentreJustify);
        _printMenuText(xPos, 56, "Save", false, eCentreJustify);
        break;
    }
  }

  return true;
}


bool 
CHeaterSettingsScreen::animate()
{ 

  if(isPasswordBusy() || _saveBusy()) {  // Password screen activity
    return false;
  }

  char msg[16];
  _animateCount++;
  WRAPUPPERLIMIT(_animateCount, 9, 0);

  if(_rowSel == 1) {
    _display.drawRect(Column-border, Line1-border, 34, 8+2*border, BLACK);
    _display.drawRoundRect(Column-border, Line1-border, 34, 8+2*border, radius, WHITE);
  }
  else {
    _printMenuText(Column, Line1, "     ");
  }

  if(_animateCount < 4) 
    sprintf(msg, "PF-%d ", _glowDrive);
  else
    sprintf(msg, "(%dW)", plugPowers[_glowDrive-1]);
  _printMenuText(Column, Line1, msg);

  int xPos = Column;
  _printMenuText(xPos, Line2, "    ", _rowSel == 2); // erase, but create selection loop
  if(_animateCount < 4) {
    sprintf(msg, "SN-%d", _fanSensor);
    _printMenuText(Column, Line2, msg);
  }
  else {
    sprintf(msg, "(\365%d)", _fanSensor);  // \365 is division character
    _printMenuText(xPos, Line2, msg);  
  }

  return true;
}


bool 
CHeaterSettingsScreen::keyHandler(uint8_t event)
{
  if(CPasswordScreen::keyHandler(event)) {  // handle confirm save
    return true;
  }

  if(CUIEditScreen::keyHandler(event)) {  // handle save confirm
    return true;
  }


  if(event & keyPressed) {
    // press LEFT to select previous screen
    if(event & key_Left) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.prevMenu();
          break;
        case 1:
        case 2:
        case 3:
          _adjust(-1);
          break;
      }
    }
    // press RIGHT to select next screen
    if(event & key_Right) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.nextMenu();
          break;
        case 1:
        case 2:
        case 3:
          _adjust(+1);
          break;
      }
    }
    if(event & key_Down) {
      _rowSel--;
      LOWERLIMIT(_rowSel, 0);
    }
    // UP press
    if(event & key_Up) {
      switch(_rowSel) {
        case 0:
        case 1:
        case 2:
        case 3:
          _rowSel++;
          UPPERLIMIT(_rowSel, 3);
          break;
      }
    }
    // CENTRE press
    if(event & key_Centre) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.selectMenu(CScreenManager::RootMenuLoop);
          break;
        case 1:
        case 2:
        case 3:
          _confirmSave();   // enter save confirm mode
          _rowSel = 0;
          break;
      }
    }
    _ScreenManager.reqUpdate();
  }

  return true;
}

void 
CHeaterSettingsScreen::_adjust(int dir)
{
  switch(_rowSel) {
    case 1:   // glow power
      _glowDrive += dir;
      BOUNDSLIMIT(_glowDrive, 1, 6);
      break;
    case 2:   // fan sensor
      _fanSensor = (_fanSensor == 1) ? 2 : 1;
      break;
    case 3:   // system voltage
      _sysVoltage = (_sysVoltage == 12) ? 24 : 12;
      break;
  }
}

void
CHeaterSettingsScreen::_saveNV()
{
  sHeaterTuning tuning = NVstore.getHeaterTuning();
  tuning.setSysVoltage(float(_sysVoltage));
  tuning.setFanSensor(_fanSensor);
  tuning.setGlowDrive(_glowDrive);
  NVstore.setHeaterTuning(tuning);
  NVstore.save();
}
