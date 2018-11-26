#include "FranklinGothic.h"

// 
//  Font data for Franklin Gothic Medium Cond 8pt
// 

// Character bitmaps for Franklin Gothic Medium Cond 8pt
const uint8_t PROGMEM franklinGothicMediumCond_8ptBitmaps [] = 
{
	// @0 ' ' (2 pixels wide)
	0x00, 0x00, //                
	0x00, 0x00, //                

	// @4 ',' (1 pixels wide)
	0xE0, // ###

	// @5 '.' (1 pixels wide)
	0x80, // #

	// @6 '/' (5 pixels wide)
	0x00, 0x40, //          #
	0x03, 0x80, //       ### 
	0x0C, 0x00, //     ##    
	0x70, 0x00, //  ###      
	0x80, 0x00, // #         

	// @16 '0' (5 pixels wide)
	0x7E, //  ###### 
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x7E, //  ###### 

	// @21 '1' (3 pixels wide)
	0x41, //  #     #
	0xFF, // ########
	0x01, //        #

	// @24 '2' (5 pixels wide)
	0x41, //  #     #
	0x83, // #     ##
	0x85, // #    # #
	0x89, // #   #  #
	0x71, //  ###   #

	// @29 '3' (5 pixels wide)
	0x42, //  #    # 
	0x81, // #      #
	0x91, // #  #   #
	0x91, // #  #   #
	0x6E, //  ## ### 

	// @34 '4' (6 pixels wide)
	0x0C, //     ##  
	0x14, //    # #  
	0x24, //   #  #  
	0x44, //  #   #  
	0xFF, // ########
	0x04, //      #  

	// @40 '5' (5 pixels wide)
	0xFA, // ##### # 
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x8E, // #   ### 

	// @45 '6' (5 pixels wide)
	0x7E, //  ###### 
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x4E, //  #  ### 

	// @50 '7' (5 pixels wide)
	0x80, // #       
	0x80, // #       
	0x8F, // #   ####
	0xB0, // # ##    
	0xC0, // ##      

	// @55 '8' (5 pixels wide)
	0x6E, //  ## ### 
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x6E, //  ## ### 

	// @60 '9' (5 pixels wide)
	0x72, //  ###  # 
	0x89, // #   #  #
	0x89, // #   #  #
	0x89, // #   #  #
	0x7E, //  ###### 

	// @65 ':' (1 pixels wide)
	0x84, // #    #

	// @66 'A' (5 pixels wide)
	0x07, //      ###
	0x3C, //   ####  
	0xC4, // ##   #  
	0x3C, //   ####  
	0x07, //      ###

	// @71 'B' (5 pixels wide)
	0xFF, // ########
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x6E, //  ## ### 

	// @76 'C' (5 pixels wide)
	0x7E, //  ###### 
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x66, //  ##  ## 

	// @81 'D' (5 pixels wide)
	0xFF, // ########
	0x81, // #      #
	0x81, // #      #
	0x42, //  #    # 
	0x3C, //   ####  

	// @86 'E' (4 pixels wide)
	0xFF, // ########
	0x91, // #  #   #
	0x91, // #  #   #
	0x81, // #      #

	// @90 'F' (4 pixels wide)
	0xFF, // ########
	0x90, // #  #    
	0x90, // #  #    
	0x80, // #       

	// @94 'G' (5 pixels wide)
	0x7E, //  ###### 
	0x81, // #      #
	0x81, // #      #
	0x89, // #   #  #
	0x6F, //  ## ####

	// @99 'H' (5 pixels wide)
	0xFF, // ########
	0x10, //    #    
	0x10, //    #    
	0x10, //    #    
	0xFF, // ########

	// @104 'I' (1 pixels wide)
	0xFF, // ########

	// @105 'J' (2 pixels wide)
	0x01, //        #
	0xFF, // ########

	// @107 'K' (5 pixels wide)
	0xFF, // ########
	0x10, //    #    
	0x38, //   ###   
	0x46, //  #   ## 
	0x81, // #      #

	// @112 'L' (4 pixels wide)
	0xFF, // ########
	0x01, //        #
	0x01, //        #
	0x01, //        #

	// @116 'M' (7 pixels wide)
	0xFF, // ########
	0xC0, // ##      
	0x3C, //   ####  
	0x03, //       ##
	0x3C, //   ####  
	0xC0, // ##      
	0xFF, // ########

	// @123 'N' (5 pixels wide)
	0xFF, // ########
	0x60, //  ##     
	0x18, //    ##   
	0x06, //      ## 
	0xFF, // ########

	// @128 'O' (5 pixels wide)
	0x7E, //  ###### 
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x7E, //  ###### 

	// @133 'P' (4 pixels wide)
	0xFF, // ########
	0x88, // #   #   
	0x88, // #   #   
	0x70, //  ###    

	// @137 'Q' (5 pixels wide)
	0x7E, 0x00, //  ######   
	0x81, 0x00, // #      #  
	0x81, 0x80, // #      ## 
	0x81, 0x40, // #      # #
	0x7E, 0x40, //  ######  #

	// @147 'R' (5 pixels wide)
	0xFF, // ########
	0x88, // #   #   
	0x8C, // #   ##  
	0x8A, // #   # # 
	0x71, //  ###   #

	// @152 'S' (5 pixels wide)
	0x62, //  ##   # 
	0x91, // #  #   #
	0x91, // #  #   #
	0x89, // #   #  #
	0x46, //  #   ## 

	// @157 'T' (5 pixels wide)
	0x80, // #       
	0x80, // #       
	0xFF, // ########
	0x80, // #       
	0x80, // #       

	// @162 'U' (5 pixels wide)
	0xFE, // ####### 
	0x01, //        #
	0x01, //        #
	0x01, //        #
	0xFE, // ####### 

	// @167 'V' (5 pixels wide)
	0xC0, // ##      
	0x3E, //   ##### 
	0x01, //        #
	0x3E, //   ##### 
	0xC0, // ##      

	// @172 'W' (7 pixels wide)
	0xF8, // #####   
	0x07, //      ###
	0x38, //   ###   
	0xC0, // ##      
	0x3C, //   ####  
	0x07, //      ###
	0xF8, // #####   

	// @179 'X' (5 pixels wide)
	0x81, // #      #
	0x66, //  ##  ## 
	0x18, //    ##   
	0x66, //  ##  ## 
	0x81, // #      #

	// @184 'Y' (5 pixels wide)
	0x80, // #       
	0x60, //  ##     
	0x1F, //    #####
	0x60, //  ##     
	0x80, // #       

	// @189 'Z' (4 pixels wide)
	0x83, // #     ##
	0x8D, // #   ## #
	0xB1, // # ##   #
	0xC1, // ##     #

	// @193 '\' (4 pixels wide)
	0x80, 0x00, // #        
	0x70, 0x00, //  ###     
	0x0E, 0x00, //     ###  
	0x01, 0x80, //        ##

	// @201 '`' (2 pixels wide)
	0x80, // # 
	0x40, //  #

	// @203 'a' (4 pixels wide)
	0x18, //    ## 
	0xA4, // # #  #
	0xA4, // # #  #
	0x7C, //  #####

	// @207 'b' (4 pixels wide)
	0xFF, // ########
	0x21, //   #    #
	0x21, //   #    #
	0x1E, //    #### 

	// @211 'c' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x48, //  #  # 

	// @215 'd' (4 pixels wide)
	0x1E, //    #### 
	0x21, //   #    #
	0x21, //   #    #
	0xFF, // ########

	// @219 'e' (4 pixels wide)
	0x78, //  #### 
	0xA4, // # #  #
	0xA4, // # #  #
	0x68, //  ## # 

	// @223 'f' (3 pixels wide)
	0x20, //   #     
	0x7F, //  #######
	0xA0, // # #     

	// @226 'g' (5 pixels wide)
	0x35, 0x00, //   ## # # 
	0x4A, 0x80, //  #  # # #
	0x4A, 0x80, //  #  # # #
	0x72, 0x80, //  ###  # #
	0x81, 0x00, // #      # 

	// @236 'h' (4 pixels wide)
	0xFF, // ########
	0x20, //   #     
	0x20, //   #     
	0x1F, //    #####

	// @240 'i' (1 pixels wide)
	0xBF, // # ######

	// @241 'j' (2 pixels wide)
	0x00, 0x40, //          #
	0xBF, 0xC0, // # ########

	// @245 'k' (4 pixels wide)
	0xFF, // ########
	0x08, //     #   
	0x16, //    # ## 
	0x21, //   #    #

	// @249 'l' (1 pixels wide)
	0xFF, // ########

	// @250 'm' (7 pixels wide)
	0xFC, // ######
	0x80, // #     
	0x80, // #     
	0x7C, //  #####
	0x80, // #     
	0x80, // #     
	0x7C, //  #####

	// @257 'n' (4 pixels wide)
	0xFC, // ######
	0x80, // #     
	0x80, // #     
	0x7C, //  #####

	// @261 'o' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x78, //  #### 

	// @265 'p' (4 pixels wide)
	0xFF, // ########
	0x84, // #    #  
	0x84, // #    #  
	0x78, //  ####   

	// @269 'q' (4 pixels wide)
	0x78, //  ####   
	0x84, // #    #  
	0x84, // #    #  
	0xFF, // ########

	// @273 'r' (3 pixels wide)
	0xFC, // ######
	0x40, //  #    
	0x80, // #     

	// @276 's' (3 pixels wide)
	0x44, //  #   #
	0xA4, // # #  #
	0x98, // #  ## 

	// @279 't' (3 pixels wide)
	0x20, //   #     
	0xFF, // ########
	0x21, //   #    #

	// @282 'u' (4 pixels wide)
	0xF8, // ##### 
	0x04, //      #
	0x08, //     # 
	0xFC, // ######

	// @286 'v' (5 pixels wide)
	0x80, // #     
	0x70, //  ###  
	0x0C, //     ##
	0x70, //  ###  
	0x80, // #     

	// @291 'w' (5 pixels wide)
	0xF0, // ####  
	0x0C, //     ##
	0xF0, // ####  
	0x0C, //     ##
	0xF0, // ####  

	// @296 'x' (3 pixels wide)
	0xCC, // ##  ##
	0x30, //   ##  
	0xCC, // ##  ##

	// @299 'y' (3 pixels wide)
	0xF1, // ####   #
	0x0E, //     ### 
	0xF0, // ####    

	// @302 'z' (3 pixels wide)
	0x8C, // #   ##
	0xB4, // # ## #
	0xC4, // ##   #
};

// Character descriptors for Franklin Gothic Medium Cond 8pt
// { [Char width in bits], [Char height in bits], [Offset into franklinGothicMediumCond_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO PROGMEM franklinGothicMediumCond_8ptDescriptors[] = 
{
	{1, 15, 0}, 		//   
	{0, 0, 0}, 		// ! 
	{0, 0, 0}, 		// " 
	{0, 0, 0}, 		// # 
	{0, 0, 0}, 		// $ 
	{0, 0, 0}, 		// % 
	{0, 0, 0}, 		// & 
	{0, 0, 0}, 		// ' 
	{0, 0, 0}, 		// ( 
	{0, 0, 0}, 		// ) 
	{0, 0, 0}, 		// * 
	{0, 0, 0}, 		// + 
	{1, 3, 4}, 		// , 
	{0, 0, 0}, 		// - 
	{1, 1, 5}, 		// . 
	{5, 10, 6}, 		// / 
	{5, 8, 16}, 		// 0 
	{3, 8, 21}, 		// 1 
	{5, 8, 24}, 		// 2 
	{5, 8, 29}, 		// 3 
	{6, 8, 34}, 		// 4 
	{5, 8, 40}, 		// 5 
	{5, 8, 45}, 		// 6 
	{5, 8, 50}, 		// 7 
	{5, 8, 55}, 		// 8 
	{5, 8, 60}, 		// 9 
	{1, 6, 65}, 		// : 
	{0, 0, 0}, 		// ; 
	{0, 0, 0}, 		// < 
	{0, 0, 0}, 		// = 
	{0, 0, 0}, 		// > 
	{0, 0, 0}, 		// ? 
	{0, 0, 0}, 		// @ 
	{5, 8, 66}, 		// A 
	{5, 8, 71}, 		// B 
	{5, 8, 76}, 		// C 
	{5, 8, 81}, 		// D 
	{4, 8, 86}, 		// E 
	{4, 8, 90}, 		// F 
	{5, 8, 94}, 		// G 
	{5, 8, 99}, 		// H 
	{1, 8, 104}, 		// I 
	{2, 8, 105}, 		// J 
	{5, 8, 107}, 		// K 
	{4, 8, 112}, 		// L 
	{7, 8, 116}, 		// M 
	{5, 8, 123}, 		// N 
	{5, 8, 128}, 		// O 
	{4, 8, 133}, 		// P 
	{5, 10, 137}, 		// Q 
	{5, 8, 147}, 		// R 
	{5, 8, 152}, 		// S 
	{5, 8, 157}, 		// T 
	{5, 8, 162}, 		// U 
	{5, 8, 167}, 		// V 
	{7, 8, 172}, 		// W 
	{5, 8, 179}, 		// X 
	{5, 8, 184}, 		// Y 
	{4, 8, 189}, 		// Z 
	{0, 0, 0}, 		// [ 
	{4, 9, 193}, 		// \ 
	{0, 0, 0}, 		// ] 
	{0, 0, 0}, 		// ^ 
	{0, 0, 0}, 		// _ 
	{2, 2, 201}, 		// ` 
	{4, 6, 203}, 		// a 
	{4, 8, 207}, 		// b 
	{4, 6, 211}, 		// c 
	{4, 8, 215}, 		// d 
	{4, 6, 219}, 		// e 
	{3, 8, 223}, 		// f 
	{5, 9, 226}, 		// g 
	{4, 8, 236}, 		// h 
	{1, 8, 240}, 		// i 
	{2, 10, 241}, 		// j 
	{4, 8, 245}, 		// k 
	{1, 8, 249}, 		// l 
	{7, 6, 250}, 		// m 
	{4, 6, 257}, 		// n 
	{4, 6, 261}, 		// o 
	{4, 8, 265}, 		// p 
	{4, 8, 269}, 		// q 
	{3, 6, 273}, 		// r 
	{3, 6, 276}, 		// s 
	{3, 8, 279}, 		// t 
	{4, 6, 282}, 		// u 
	{5, 6, 286}, 		// v 
	{5, 6, 291}, 		// w 
	{3, 6, 296}, 		// x 
	{3, 8, 299}, 		// y 
	{3, 6, 302}, 		// z 
};


// Font information for Franklin Gothic Medium Cond 8pt
const FONT_INFO franklinGothicMediumCond_8ptFontInfo =
{
	15, //  Character height
	' ', //  Start character
	'z', //  End character
	1, //  Width, in pixels, of space character
	franklinGothicMediumCond_8ptDescriptors, //  Character descriptor array
	franklinGothicMediumCond_8ptBitmaps, //  Character bitmap array
};

// 
//  Font data for Franklin Gothic Medium Cond 7pt
// 

// Character bitmaps for Franklin Gothic Medium Cond 7pt
const uint8_t PROGMEM franklinGothicMediumCond_7ptBitmaps [] = 
{
	// @0 ' ' (2 pixels wide)
	0x00, 0x00, //             
	0x00, 0x00, //             

	// @4 ',' (1 pixels wide)
	0xC0, // ##

	// @5 '.' (1 pixels wide)
	0x80, // #

	// @6 '/' (4 pixels wide)
	0x01, //        #
	0x0E, //     ### 
	0x70, //  ###    
	0x80, // #       

	// @10 '0' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x78, //  #### 

	// @14 '1' (3 pixels wide)
	0x44, //  #   #
	0xFC, // ######
	0x04, //      #

	// @17 '2' (4 pixels wide)
	0x44, //  #   #
	0x8C, // #   ##
	0x94, // #  # #
	0x64, //  ##  #

	// @21 '3' (4 pixels wide)
	0x48, //  #  # 
	0x84, // #    #
	0xA4, // # #  #
	0x58, //  # ## 

	// @25 '4' (5 pixels wide)
	0x18, //    ## 
	0x68, //  ## # 
	0x88, // #   # 
	0xFC, // ######
	0x08, //     # 

	// @30 '5' (4 pixels wide)
	0xE8, // ### # 
	0xA4, // # #  #
	0xA4, // # #  #
	0x98, // #  ## 

	// @34 '6' (4 pixels wide)
	0x78, //  #### 
	0xA4, // # #  #
	0xA4, // # #  #
	0x18, //    ## 

	// @38 '7' (4 pixels wide)
	0x80, // #     
	0x9C, // #  ###
	0xA0, // # #   
	0xC0, // ##    

	// @42 '8' (4 pixels wide)
	0x58, //  # ## 
	0xA4, // # #  #
	0xA4, // # #  #
	0x58, //  # ## 

	// @46 '9' (4 pixels wide)
	0x60, //  ##   
	0x94, // #  # #
	0x94, // #  # #
	0x78, //  #### 

	// @50 ':' (1 pixels wide)
	0x88, // #   #

	// @51 'A' (3 pixels wide)
	0x3C, //   ####
	0xC8, // ##  # 
	0x3C, //   ####

	// @54 'B' (4 pixels wide)
	0xFC, // ######
	0xA4, // # #  #
	0xA4, // # #  #
	0x58, //  # ## 

	// @58 'C' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x48, //  #  # 

	// @62 'D' (4 pixels wide)
	0xFC, // ######
	0x84, // #    #
	0x84, // #    #
	0x78, //  #### 

	// @66 'E' (3 pixels wide)
	0xFC, // ######
	0xA4, // # #  #
	0xA4, // # #  #

	// @69 'F' (3 pixels wide)
	0xFC, // ######
	0x90, // #  #  
	0x90, // #  #  

	// @72 'G' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x94, // #  # #
	0x5C, //  # ###

	// @76 'H' (4 pixels wide)
	0xFC, // ######
	0x20, //   #   
	0x20, //   #   
	0xFC, // ######

	// @80 'I' (1 pixels wide)
	0xFC, // ######

	// @81 'J' (2 pixels wide)
	0x04, //      #
	0xFC, // ######

	// @83 'K' (4 pixels wide)
	0xFC, // ######
	0x20, //   #   
	0x58, //  # ## 
	0x84, // #    #

	// @87 'L' (3 pixels wide)
	0xFC, // ######
	0x04, //      #
	0x04, //      #

	// @90 'M' (5 pixels wide)
	0xFC, // ######
	0x60, //  ##   
	0x1C, //    ###
	0x60, //  ##   
	0xFC, // ######

	// @95 'N' (4 pixels wide)
	0xFC, // ######
	0x60, //  ##   
	0x18, //    ## 
	0xFC, // ######

	// @99 'O' (4 pixels wide)
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x78, //  #### 

	// @103 'P' (3 pixels wide)
	0xFC, // ######
	0x90, // #  #  
	0x60, //  ##   

	// @106 'Q' (4 pixels wide)
	0x78, //  ####  
	0x84, // #    # 
	0x86, // #    ##
	0x7A, //  #### #

	// @110 'R' (4 pixels wide)
	0xFC, // ######
	0x90, // #  #  
	0x98, // #  ## 
	0x64, //  ##  #

	// @114 'S' (4 pixels wide)
	0x48, //  #  # 
	0xA4, // # #  #
	0x94, // #  # #
	0x48, //  #  # 

	// @118 'T' (3 pixels wide)
	0x80, // #     
	0xFC, // ######
	0x80, // #     

	// @121 'U' (4 pixels wide)
	0xF8, // ##### 
	0x04, //      #
	0x04, //      #
	0xF8, // ##### 

	// @125 'V' (3 pixels wide)
	0xF0, // ####  
	0x0C, //     ##
	0xF0, // ####  

	// @128 'W' (5 pixels wide)
	0xF0, // ####  
	0x0C, //     ##
	0xF0, // ####  
	0x0C, //     ##
	0xF0, // ####  

	// @133 'X' (3 pixels wide)
	0xCC, // ##  ##
	0x30, //   ##  
	0xCC, // ##  ##

	// @136 'Y' (5 pixels wide)
	0x80, // #     
	0x60, //  ##   
	0x1C, //    ###
	0x60, //  ##   
	0x80, // #     

	// @141 'Z' (3 pixels wide)
	0x8C, // #   ##
	0xB4, // # ## #
	0xC4, // ##   #

	// @144 '\' (4 pixels wide)
	0x80, // #       
	0x70, //  ###    
	0x0C, //     ##  
	0x03, //       ##

	// @148 '`' (2 pixels wide)
	0x80, // # 
	0x40, //  #

	// @150 'a' (3 pixels wide)
	0x90, // #  # 
	0xA8, // # # #
	0x78, //  ####

	// @153 'b' (3 pixels wide)
	0xFC, // ######
	0x44, //  #   #
	0x38, //   ### 

	// @156 'c' (3 pixels wide)
	0x70, //  ### 
	0x88, // #   #
	0x50, //  # # 

	// @159 'd' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0xFC, // ######

	// @162 'e' (3 pixels wide)
	0x70, //  ### 
	0xA8, // # # #
	0x68, //  ## #

	// @165 'f' (2 pixels wide)
	0x7C, //  #####
	0xA0, // # #   

	// @167 'g' (4 pixels wide)
	0x2A, //   # # # 
	0x55, //  # # # #
	0x65, //  ##  # #
	0x82, // #     # 

	// @171 'h' (3 pixels wide)
	0xFC, // ######
	0x40, //  #    
	0x3C, //   ####

	// @174 'i' (1 pixels wide)
	0xBE, // # #####

	// @175 'j' (2 pixels wide)
	0x00, 0x80, //         #
	0xBF, 0x80, // # #######

	// @179 'k' (3 pixels wide)
	0xFC, // ######
	0x30, //   ##  
	0x4C, //  #  ##

	// @182 'l' (1 pixels wide)
	0xFC, // ######

	// @183 'm' (5 pixels wide)
	0xF8, // #####
	0x80, // #    
	0xF8, // #####
	0x80, // #    
	0x78, //  ####

	// @188 'n' (3 pixels wide)
	0xF8, // #####
	0x80, // #    
	0x78, //  ####

	// @191 'o' (3 pixels wide)
	0x70, //  ### 
	0x88, // #   #
	0x70, //  ### 

	// @194 'p' (3 pixels wide)
	0xFE, // #######
	0x88, // #   #  
	0x70, //  ###   

	// @197 'q' (3 pixels wide)
	0x70, //  ###   
	0x88, // #   #  
	0xFE, // #######

	// @200 'r' (3 pixels wide)
	0xF8, // #####
	0x40, //  #   
	0x80, // #    

	// @203 's' (3 pixels wide)
	0x48, //  #  #
	0xA8, // # # #
	0x90, // #  # 

	// @206 't' (2 pixels wide)
	0xFC, // ######
	0x44, //  #   #

	// @208 'u' (3 pixels wide)
	0xF0, // #### 
	0x08, //     #
	0xF8, // #####

	// @211 'v' (3 pixels wide)
	0xE0, // ###  
	0x18, //    ##
	0xE0, // ###  

	// @214 'w' (5 pixels wide)
	0xE0, // ###  
	0x18, //    ##
	0xE0, // ###  
	0x18, //    ##
	0xE0, // ###  

	// @219 'x' (3 pixels wide)
	0x88, // #   #
	0x70, //  ### 
	0x88, // #   #

	// @222 'y' (3 pixels wide)
	0xE2, // ###   #
	0x1C, //    ### 
	0xE0, // ###    

	// @225 'z' (2 pixels wide)
	0xB8, // # ###
	0xC8, // ##  #
};

// Character descriptors for Franklin Gothic Medium Cond 7pt
// { [Char width in bits], [Char height in bits], [Offset into franklinGothicMediumCond_7ptCharBitmaps in bytes] }
const FONT_CHAR_INFO PROGMEM franklinGothicMediumCond_7ptDescriptors[] = 
{
	{1, 7, 0}, 		//   
	{0, 0, 0}, 		// ! 
	{0, 0, 0}, 		// " 
	{0, 0, 0}, 		// # 
	{0, 0, 0}, 		// $ 
	{0, 0, 0}, 		// % 
	{0, 0, 0}, 		// & 
	{0, 0, 0}, 		// ' 
	{0, 0, 0}, 		// ( 
	{0, 0, 0}, 		// ) 
	{0, 0, 0}, 		// * 
	{0, 0, 0}, 		// + 
	{1, 2, 4}, 		// , 
	{0, 0, 0}, 		// - 
	{1, 1, 5}, 		// . 
	{4, 8, 6}, 		// / 
	{4, 6, 10}, 		// 0 
	{3, 6, 14}, 		// 1 
	{4, 6, 17}, 		// 2 
	{4, 6, 21}, 		// 3 
	{5, 6, 25}, 		// 4 
	{4, 6, 30}, 		// 5 
	{4, 6, 34}, 		// 6 
	{4, 6, 38}, 		// 7 
	{4, 6, 42}, 		// 8 
	{4, 6, 46}, 		// 9 
	{1, 5, 50}, 		// : 
	{0, 0, 0}, 		// ; 
	{0, 0, 0}, 		// < 
	{0, 0, 0}, 		// = 
	{0, 0, 0}, 		// > 
	{0, 0, 0}, 		// ? 
	{0, 0, 0}, 		// @ 
	{3, 6, 51}, 		// A 
	{4, 6, 54}, 		// B 
	{4, 6, 58}, 		// C 
	{4, 6, 62}, 		// D 
	{3, 6, 66}, 		// E 
	{3, 6, 69}, 		// F 
	{4, 6, 72}, 		// G 
	{4, 6, 76}, 		// H 
	{1, 6, 80}, 		// I 
	{2, 6, 81}, 		// J 
	{4, 6, 83}, 		// K 
	{3, 6, 87}, 		// L 
	{5, 6, 90}, 		// M 
	{4, 6, 95}, 		// N 
	{4, 6, 99}, 		// O 
	{3, 6, 103}, 		// P 
	{4, 7, 106}, 		// Q 
	{4, 6, 110}, 		// R 
	{4, 6, 114}, 		// S 
	{3, 6, 118}, 		// T 
	{4, 6, 121}, 		// U 
	{3, 6, 125}, 		// V 
	{5, 6, 128}, 		// W 
	{3, 6, 133}, 		// X 
	{5, 6, 136}, 		// Y 
	{3, 6, 141}, 		// Z 
	{0, 0, 0}, 		// [ 
	{4, 8, 144}, 		// \ 
	{0, 0, 0}, 		// ] 
	{0, 0, 0}, 		// ^ 
	{0, 0, 0}, 		// _ 
	{2, 2, 148}, 		// ` 
	{3, 5, 150}, 		// a 
	{3, 6, 153}, 		// b 
	{3, 5, 156}, 		// c 
	{3, 6, 159}, 		// d 
	{3, 5, 162}, 		// e 
	{2, 6, 165}, 		// f 
	{4, 8, 167}, 		// g 
	{3, 6, 171}, 		// h 
	{1, 7, 174}, 		// i 
	{2, 9, 175}, 		// j 
	{3, 6, 179}, 		// k 
	{1, 6, 182}, 		// l 
	{5, 5, 183}, 		// m 
	{3, 5, 188}, 		// n 
	{3, 5, 191}, 		// o 
	{3, 7, 194}, 		// p 
	{3, 7, 197}, 		// q 
	{3, 5, 200}, 		// r 
	{3, 5, 203}, 		// s 
	{2, 6, 206}, 		// t 
	{3, 5, 208}, 		// u 
	{3, 5, 211}, 		// v 
	{5, 5, 214}, 		// w 
	{3, 5, 219}, 		// x 
	{3, 7, 222}, 		// y 
	{2, 5, 225}, 		// z 
};

// Font information for Franklin Gothic Medium Cond 7pt
const FONT_INFO franklinGothicMediumCond_7ptFontInfo =
{
	12, //  Character height
	' ', //  Start character
	'z', //  End character
  1,  // width of space
	franklinGothicMediumCond_7ptDescriptors, //  Character descriptor array
	franklinGothicMediumCond_7ptBitmaps, //  Character bitmap array
};
