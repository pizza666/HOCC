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
#include "map.h"

/* global defines */
#define SCREENRAM 0xC000
#define SCREENRAM_PTR ((unsigned char *) SCREENRAM)
#define SCREENRAM_HI 0xC0
#define SCREENRAM_HI_PTR (*(unsigned char *) 0x0288)

#define VIC_BANK_OFFSET 0xd018
#define VIC_BANK_SETUP 0xdd00
#define VIC_CHR_BANK ((unsigned char*) 0xC800)
#define SCREENWIDTH 40
#define SCREENSIZE 1000
#define MULTICOLOR 16

/* global vars */
extern unsigned char ui[2000];
extern unsigned char buffer[2000];
extern unsigned char keyin;
extern unsigned char joyin;
extern Player p;
extern Map map;
extern unsigned char fov[11];
extern unsigned char lzbuffer[1074];
extern unsigned char volume;

#endif