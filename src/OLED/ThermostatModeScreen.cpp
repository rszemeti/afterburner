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

//#include "128x64OLED.h"
#include "ThermostatModeScreen.h"
#include "KeyPad.h"
#include "../Utility/helpers.h"
#include "../Utility/UtilClasses.h"
#include "fonts/Icons.h"


///////////////////////////////////////////////////////////////////////////
//
// CThermostatModeScreen
//
// This screen provides control over experimental features
//
///////////////////////////////////////////////////////////////////////////

static const int Line3 = 14;
static const int Line2 = 27;
static const int Line1 = 40;
static const int Column = 40;

CThermostatModeScreen::CThermostatModeScreen(C128x64_OLED& display, CScreenManager& mgr) : CPasswordScreen(display, mgr) 
{
  _initUI();
  _window = 10;
  _thermoMode = 0;
  _cyclicMode.init();
}

void 
CThermostatModeScreen::onSelect()
{
  CPasswordScreen::onSelect();
  _initUI();
  _window = NVstore.getUserSettings().ThermostatWindow;
  _thermoMode = NVstore.getUserSettings().ThermostatMethod;
  _cyclicMode = NVstore.getUserSettings().cyclic;
}

void
CThermostatModeScreen::_initUI()
{
  _rowSel = 0;
  _animateCount = 0;
  _keyRepeat = -1;
}

bool 
CThermostatModeScreen::show()
{
  char msg[20];
  _display.clearDisplay();

  if(!CPasswordScreen::show()) {  // for showing "saving settings"

    if(_rowSel == 10) {
      _printInverted(_display.xCentre(), 0, " Saving Settings ", true, eCentreJustify);
      _printMenuText(_display.xCentre(), 35, "Press UP to", false, eCentreJustify);
      _printMenuText(_display.xCentre(), 43, "confirm save", false, eCentreJustify);
    }
    else {
      _printInverted(_display.xCentre(), 0, " Thermostat Mode ", true, eCentreJustify);
      _drawBitmap(3, 14, ThermostatIconInfo);
      float fTemp = _window;
      if(NVstore.getUserSettings().degF) {
        fTemp = fTemp * 9 / 5;
        sprintf(msg, "%.1f\367F", fTemp);
      }
      else {
        sprintf(msg, "%.1f\367C", fTemp);
      }
      _printMenuText(Column, Line2, msg, _rowSel == 3);
      switch(_thermoMode) {
        case 1: 
          _printMenuText(Column, Line3, "Deadband", _rowSel == 4);
          break;
        case 2: 
          _printMenuText(Column, Line3, "Linear Hz", _rowSel == 4);
          break;
        default: 
          _printMenuText(Column, Line3, "Standard", _rowSel == 4);
          break;
      }
      if(_cyclicMode.isEnabled()) {
        float fTemp = _cyclicMode.Stop+1;
        if(NVstore.getUserSettings().degF) {
          fTemp = fTemp * 9 / 5;
          sprintf(msg, "\352>%.0f\367F", fTemp);
        }
        else {
          sprintf(msg, "\352>%.0f\367C", fTemp);
        }
      }
      else {
        strcpy(msg, "OFF");
      }
      _printMenuText(Column, Line1, msg, _rowSel == 1);
      if(_cyclicMode.isEnabled()) {
        float fTemp = _cyclicMode.Start;
  //    if(NVstore.getDegFMode()) {
        if(NVstore.getUserSettings().degF) {
          fTemp = fTemp * 9 / 5;
          sprintf(msg, "\352<%.0f\367F", fTemp);
        }
        else {
          sprintf(msg, "\352<%.0f\367C", fTemp);
        }
      }
      else {
        strcpy(msg, "");
      }
      _printMenuText(Column + 42, Line1, msg, _rowSel == 2);
    }
  }

  return true;
}

bool 
CThermostatModeScreen::animate()
{
  if(_rowSel != 10) {
    int yPos = 53;
    int xPos = _display.xCentre();
    const char* pMsg = NULL;
    switch(_rowSel) {
      case 0:
        _printMenuText(xPos, yPos, " \021  \030Edit  Exit   \020 ", true, eCentreJustify);
        break;
      case 1:
        _display.drawFastHLine(0, 52, 128, WHITE);
        pMsg = "                    Heater shuts down over set point.                    ";
        _scrollMessage(56, pMsg, _scrollChar);
        break;
      case 2:
        _display.drawFastHLine(0, 52, 128, WHITE);
        pMsg = "                    Heater restarts below setpoint.                    ";
        _scrollMessage(56, pMsg, _scrollChar);
        break;
      case 3:
        _display.drawFastHLine(0, 52, 128, WHITE);
        pMsg = "                    User defined window for custom thermostat modes.                    ";
        _scrollMessage(56, pMsg, _scrollChar);
        break;
      case 4:
        _display.drawFastHLine(0, 52, 128, WHITE);
        switch(_thermoMode) {
          case 1:
            pMsg = "                   The user defined window sets the thermostat's hysteresis.                    ";
            break;
          case 2:
            pMsg = "                   The pump rate is adjusted linearly across the set point window.                    ";
            break;
          default:
            pMsg = "                   Use heater's standard thermostat control.                    ";
            break;
        }
        if(pMsg)
          _scrollMessage(56, pMsg, _scrollChar);
        break;
    }
    return true;
  }
  return false;
}

bool 
CThermostatModeScreen::keyHandler(uint8_t event)
{
  sUserSettings settings;
  if(event & keyPressed) {
    _keyRepeat = 0;  // unlock hold function
    // press LEFT to select previous screen
    if(event & key_Left) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.prevMenu();
          break;
        case 4:
          _scrollChar = 0;
        case 1:
        case 2:
        case 3:
          _adjust(-1);
          break;
        case 10:
          _rowSel = 0;   // abort save
          break;
      }
    }
    // press RIGHT to select next screen
    if(event & key_Right) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.nextMenu();
          break;
        case 4:
          _scrollChar = 0;
        case 1:
        case 2:
        case 3:
          _adjust(+1);
          break;
        case 10:
          _rowSel = 0;   // abort save
          break;
      }
    }
    if(event & key_Down) {
      if(_rowSel != 0) {
        _scrollChar = 0;
        _rowSel--;
        if(_rowSel == 2 && !_cyclicMode.isEnabled()) 
          _rowSel--;
        LOWERLIMIT(_rowSel, 0);
      }
    }
    // UP press
    if(event & key_Up) {
      switch(_rowSel) {
        case 0:
        case 1:
        case 2:
        case 3:
          _scrollChar = 0;
          _rowSel++;
          if(_rowSel == 2 && !_cyclicMode.isEnabled()) 
            _rowSel++;
          UPPERLIMIT(_rowSel, 4);
          break;
        case 10:    // confirmed save
          _showStoringMessage();
          settings = NVstore.getUserSettings();
          settings.ThermostatMethod = _thermoMode;
          settings.ThermostatWindow = _window;
          settings.cyclic = _cyclicMode;
          NVstore.setUserSettings(settings);
          saveNV();
          _rowSel = 0;
          break;
      }
    }
    // CENTRE press
    if(event & key_Centre) {
      switch(_rowSel) {
        case 0:
          _ScreenManager.selectMenu(CScreenManager::RootMenuLoop, CScreenManager::SettingsUI);  // force return to main menu
          break;
        case 1:
        case 2:
        case 3:
        case 4:
          _rowSel = 10;
          break;
      }
    }
    _ScreenManager.reqUpdate();
  }
  if(event & keyRepeat) {
    _keyRepeat++;
    if((event & key_Down) && (keyRepeat >= 4)) {
      _keyRepeat = -1;
      if(_rowSel == 0) {
        _ScreenManager.selectMenu(CScreenManager::BranchMenu, CScreenManager::FontDumpUI);
      }
    }
    if(_rowSel == 3) {
      if(event & key_Right) {
        _adjust(+1);
        _ScreenManager.reqUpdate();
      }
      if(event & key_Left) {
        _adjust(-1);
        _ScreenManager.reqUpdate();
      }
    }
  }
  if(event & keyReleased) {
    _keyRepeat = -1;
  }

  return true;
}

void 
CThermostatModeScreen::_adjust(int dir)
{
  switch(_rowSel) {
    case 1:
      _cyclicMode.Stop += dir;
      BOUNDSLIMIT(_cyclicMode.Stop, 0, 9);
      break;
    case 2:
      _cyclicMode.Start += dir;
      BOUNDSLIMIT(_cyclicMode.Start, -20, 0);
      break;
    case 3:   // window
      _window += (dir * 0.1);
      BOUNDSLIMIT(_window, 0.2, 10.0);
      break;
    case 4:   // thermostat mode
      _thermoMode += dir;
      WRAPLIMITS(_thermoMode, 0, 2);
      break;
  }
}