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

#include "MiniFont.h"
// 
//  Font data for a 3x5 font
//  Hand carved by Ray Jones, based upon The Dot Factory font tool output structures
// 

// Character bitmaps for a 3x5 font
const uint8_t miniFontBitmaps[] PROGMEM =
{
	// @0 '.' (1 pixels wide)
	0x08,   //      #   

	// @1 '0' (3 pixels wide)
	0x70,   //   ###
	0x88,   //  #   #
	0x70,   //   ###

	// @4 '1' (3 pixels wide)
	0x48,   //   #  #
	0xf8,   //  #####
	0x08,   //      #

	// @7 '2' (3 pixels wide)
	0x98,   // #  ##
	0xa8,   // # # #
	0x48,   //  #  #

	// @10 '3' (3 pixels wide)
	0x88,   // #   #
	0xa8,   // # # #
	0xf8,   // #####

	// @13 '4' (3 pixels wide)
	0xe0,   //  ###    
	0x20,   //    #    
	0xf8,   //  #####    

	// @16 '5' (3 pixels wide)
	0xe8,   //  ### #
	0xa8,   //  # # #
	0x90,   //  #  #

	// @19 '6' (3 pixels wide)
	0x78,   //   ####
	0xa8,   //  # # #  
	0xb8,   //  # ###   

	// @22 '7' (3 pixels wide)
	0x80,   //  #
	0x80,   //  #
	0xf8,   //  #####

	// @25 '8' (3 pixels wide)
	0xf8,   //  #####
	0xa8,   //  # # #
	0xF8,   //  #####

	// @28 '9' (3 pixels wide)
	0xe8,   //  ### #
	0xa8,   //  # # #
	0xF0,   //  ####

	// @31 '`' (2 pixels wide)
	0xC0,   //   ##          
	0xC0,   //   ##          

	// @33 'A' (3 pixels wide)
	0x78,   //   ####
	0xa0,   //  # #
	0x78,   //   ####

	// @36 'C' (3 pixels wide)
	0x70,   //   ###
	0x88,   //  #   #
	0x88,   //  #   #

  // @39 'F' (3 pixels wise)
	0xf8,   //  #####
	0xa0,   //  # #
	0x80,   //  # 

  // @42 'G' (3 pixels wise)
	0xf8,   //  #####
	0x88,   //  #   #
	0x98,   //  #  ## 

	// @45 'H' (3 pixels wide)
	0xf8,   //  #####
	0x20,   //    #
	0xf8,   //  #####

  // @48'L' (3 pixels wise)
	0xf8,   //  ##### 
	0x08,   //      #
	0x08,   //      #

	// @51 'P' (3 pixels wide)
	0xf8,   //  #####
	0xa0,   //  # #
	0xe0,   //  ###

  // @54 'T' (3 pixels wise)
	0x80,   //  #
	0xf8,   //  #####
	0x80,   //  # 

	// @57 'V' (3 pixels wide)
	0xf0,   //  ####
	0x08,   //      #
	0xf0,   //  ####

	// @60 'W' (3 pixels wide)
	0xf8,   //  #####
	0x10,   //     #
	0xf8,   //  #####

	// @63 'z' (3 pixels wide)
	0x28,   //    # #
	0x38,   //    ###
	0x28,   //    # #

	// @66 'R' (3 pixels wide)
	0xf8,   //    #####
	0xa0,   //    # #
	0x58,   //     # ##

	// @69 'S' (3 pixels wide)
	0xe8,   //    ### #
	0xa8,   //    # # #
	0xb8,   //    # ###

	// @72 'E' (3 pixels wide)
	0xf8,   //    #####
	0xa8,   //    # # #
	0x88,   //    #   #

	// @75 'W' (3 pixels wide)
	0xf8,   //  #####
	0x40,   //   #  
	0xf8,   //  #####

	// @78 'o' (3 pixels wide)
	0x70,   //   ###
	0x88,   //  #   #
	0x70,   //   ###

  // @81 ':' (1 pixel wide)
  0x50,   //   # # 

  // @82 'b' (3 pixels wide)
	0xf8,   //  #####
	0x28,   //    # # 
	0x38,   //    ###

  // @85 'd' (3 pixels wide)
	0x38,   //    ###
	0x28,   //    # # 
	0xf8,   //  #####

  // @88 '-' (3 pixels wide)
	0x20,   //    #  
	0x20,   //    #  
	0x20,   //    #  

  // @91 'N' (3 pixels wide)
  0xf8,   //  #####
  0x20,   //    #  
  0xf8,   //  #####

  // @94 'Y' (3 pixels wide)
  0xc0,   //  ##   
  0x38,   //    ###
  0xc0,   //  ##   

  // @97 'a' (3 pixels wide)
  0x10,   //     # 
  0x28,   //    # #
  0x38,   //    ###

  // @100 'n' (3 pixels wide)
  0x38,   //    ###
  0x20,   //    #  
  0x38,   //    ###

  // @103 'O' (3 pixels wide)
  0xF8,   //  #####
  0x88,   //  #   #
  0xF8,   //  #####

  // @106 'r' (3 pixels wide)
  0x38,   //    ###
  0x20,   //    #  
  0x20,   //    #  
};

// Character descriptors for a 3x5 font
// { [Char width in bits], [Char height in bits], [Offset into tahoma_16ptCharBitmaps in bytes] }
const FONT_CHAR_INFO miniFontDescriptors[] PROGMEM =
{
	{3, 5, 88}, 		// '-' 
	{1, 5, 0},      // '.' 
	{0, 0, 0},      // '/' 
	{3, 5, 1},      // '0' 
	{3, 5, 4},      // '1' 
	{3, 5, 7},      // '2' 
	{3, 5, 10},     // '3' 
	{3, 5, 13},     // '4' 
	{3, 5, 16},     // '5' 
	{3, 5, 19},     // '6' 
	{3, 5, 22},     // '7' 
	{3, 5, 25},     // '8' 
	{3, 5, 28},     // '9' 
	{1, 5, 81},     // ':' 
	{0, 0, 0},      // ';' 
	{0, 0, 0},      // '<' 
	{0, 0, 0},      // '='
	{0, 0, 0},      // '>'
	{0, 0, 0},      // '?' 
	{0, 0, 0},      // '@' 
	{3, 5, 33},     // 'A' 
	{3, 5, 82},     // 'B' 
	{3, 5, 36},     // 'C' 
	{3, 5, 85},     // 'D' 
	{3, 5, 72},     // 'E' 
	{3, 5, 39},     // 'F' 
	{3, 5, 42},     // 'G' 
	{3, 5, 45},     // 'H' 
	{0, 0, 0},      // 'I' 
	{0, 0, 0},      // 'J' 
	{0, 0, 0},      // 'K' 
	{3, 5, 48},     // 'L' 
	{3, 5, 75},     // 'M' 
	{3, 5, 91},     // 'N' 
	{3, 5, 103},    // 'O' 
	{3, 5, 51},     // 'P' 
	{0, 0, 0},      // 'Q' 
	{3, 5, 66},     // 'R' 
	{3, 5, 69},     // 'S' 
	{3, 5, 54},     // 'T' 
	{0, 0, 0},      // 'U' 
	{3, 5, 57},     // 'V' 
	{3, 5, 60},     // 'W' 
	{0, 0, 0},      // 'X' 
	{3, 5, 94},     // 'Y' 
	{0, 0, 0},      // 'Z' 
	{0, 0, 0},      // '[' 
	{0, 0, 0},      // '\'
	{0, 0, 0},      // ']' 
	{0, 0, 0},      // '^' 
	{0, 0, 0},      // '_' 
	{2, 5, 31},     // '`'   use for degree symbol
	{3, 5, 97},     // 'a' 
	{0, 0, 0},      // 'b' 
	{0, 0, 0},      // 'c' 
	{0, 0, 0},      // 'd' 
	{0, 0, 0},      // 'e' 
	{0, 0, 0},      // 'f' 
	{0, 0, 0},      // 'g' 
	{0, 0, 0},      // 'h' 
	{0, 0, 0},      // 'i' 
	{0, 0, 0},      // 'j' 
	{0, 0, 0},      // 'k' 
	{0, 0, 0},      // 'l' 
	{0, 0, 0},      // 'm' 
	{3, 5, 100},    // 'n' 
	{3, 5, 78},     // 'O' 
	{0, 0, 0},      // 'p' 
	{0, 0, 0},      // 'q' 
	{3, 5, 106},    // 'r' 
	{0, 0, 0},      // 's' 
	{0, 0, 0},      // 't' 
	{0, 0, 0},      // 'u' 
	{0, 0, 0},      // 'v' 
	{0, 0, 0},      // 'w' 
	{0, 0, 0},      // 'x' 
	{0, 0, 0},      // 'y' 
	{3, 5, 63},     // 'z' 
};

// Font information for Mini Font, a 3x5 font
// easier to leave in RAM, not that big anyway
const FONT_INFO miniFontInfo =
{
	5,    //  Character height
	'-',  //  Start character
  'z',  // End character
	1,    //  Width, in pixels, of space character
	miniFontDescriptors, //  Character descriptor array
	miniFontBitmaps,     //  Character bitmap array
};

