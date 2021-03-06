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

#include "Moderator.h"
#include "DebugPort.h"
#include "../Utility/helpers.h"

CTimerModerator::CTimerModerator()
{
  reset();
}

const char* 
CTimerModerator::_getName(eType type) 
{
  switch(type) {
    case eStart: return "TimerStart";
    case eStop: return "TimerStop";
    case eDays: return "TimerDays";
    case eRpt: return "TimerRepeat";
    case eTemp: return "TimerTemp";
    default: return "TimerType?";
  }
}

int 
CTimerModerator::_shouldSend(int timer, const sTimer& toSend)
{
  int retval = 0;
  if(Memory[timer].start != toSend.start)
    retval |= (0x01 << eStart);
  if(Memory[timer].stop != toSend.stop)
    retval |= (0x01 << eStop);
  if(Memory[timer].enabled != toSend.enabled)
    retval |= (0x01 << eDays);
  if(Memory[timer].repeat != toSend.repeat)
    retval |= (0x01 << eRpt);
  if(Memory[timer].temperature != toSend.temperature)
    retval |= (0x01 << eTemp);

  Memory[timer] = toSend;

  return retval;
}

bool 
CTimerModerator::addJson(int timer, const sTimer& toSend, JsonObject& root)
{
  int retval = _shouldSend(timer, toSend);
  if( retval ) {
    for(int JSONtype=0; JSONtype<5; JSONtype++) {
      if(retval & (0x01 << JSONtype))
        root.set(_getName(eType(JSONtype)), getTimerJSONStr(timer, JSONtype));
    }
  }
  return retval != 0;
}

void
CTimerModerator::reset()
{
  for(int timer= 0; timer < 14; timer++) {
    Memory[timer].start.hour = -1;  // force full update
    Memory[timer].stop.hour = -1;  // force full update
    Memory[timer].enabled = 0xff;  // invalid combination - force full update
    Memory[timer].repeat = 0xff;    
    Memory[timer].temperature = 0xff;  
  } 
}

void
CTimerModerator::reset(int timer)
{
  if(INBOUNDS(timer, 0, 13)) {
    Memory[timer].start.hour = -1;  // force full update
    Memory[timer].stop.hour = -1;  // force full update
    Memory[timer].enabled = 0xff;  // invalid combination - force full update
    Memory[timer].repeat = 0xff;    
    Memory[timer].temperature = 0xff;  
  } 
}


const char* 
CStringModerator::shouldSend(const char* name, const char* value) 
{
  std::string sValue = value;
  auto it = Memory.find(name);
  if(it != Memory.end()) {
    if(it->second == sValue)
      return NULL;    // unchanged
    it->second = sValue;
    return it->second.c_str();
  }
  else {
    return (Memory[name] = sValue).c_str();
  }
}

bool 
CStringModerator::addJson(const char* name, const char* value, JsonObject& root) 
{
  const char* toSend = shouldSend(name, value);  // returns pointer to mapped value - persistent!!!!
  if(toSend) {
    root.set(name, toSend);  // use std::string held in this class's Memory - can trust this is persistent!
    return true;
  }
  return false;
}

void 
CStringModerator::reset() 
{
 	for(auto it = Memory.begin(); it != Memory.end(); ++it) {
    Memory.erase(it);
  } 
}

void 
CStringModerator::reset(const char* name)
{
  auto it = Memory.find(name);
  if(it != Memory.end()) {
    Memory.erase(it);
  }
}
