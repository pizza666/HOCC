/********************************************************
 * global.h 
 ********************************************************
 * Global declarations
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include "player.h"
#include "canvas.h"

/* global defines */
#define SCREENRAM 0xC000
#define SCREENRAM_HI (SCREENRAM >> 8)
#define SCREEN_RAM_HI_PTR 0x0288

#define VIC_BANK_OFFSET 0xd018
#define VIC_BANK_SETUP 0xdd00
#define VIC_CHR_BANK_4 0xC800
#define VIC_CHR_BANK_5 0x2800
#define SCREENWIDTH 40
#define SCREENSIZE 1000
#define MULTICOLOR 16


/* global vars */
extern unsigned char buffer[2048];
extern unsigned char keyin;
extern Player p;
extern CanvasData canvasData;

#endif