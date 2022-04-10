/*********************************************************
 * hoc.h 
 *********************************************************
 * Main include for Halls of Curruption
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _HOC_H
#define _HOC_H

// std includes
#include <cbm.h>
#include <c64.h>
#include <conio.h>
#include <peekpoke.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* enable debugging */
#define DEBUG

/* custom includes */
#include "global.h"
#include "input.h"
#include "player.h"
#include "file.h"

/* memory map and defines*/
#define SCREENRAM 0x0400
#define VIC_MEMSETUP 0xd018
#define VIC_CHR_BANK_4 0x2000
#define VIC_CHR_BANK_5 0x2800
#define SCREENSIZE 1000
#define MULTICOLOR 16

unsigned char buffer[2048];
unsigned char keyin;
Player p;

int uiDraw()
{
    // load ui charmap
    fileOpen("ui",2);
    fileRead(&buffer);
    fileClose(2);
    memcpy(SCREENRAM, &buffer, SCREENSIZE);        // chars 
    memcpy(COLOR_RAM, &buffer[SCREENSIZE], SCREENSIZE);  // color
}

int charsetLoad(const char *filename)
{
    // load charset
    fileOpen(filename,2); 
    fileRead(VIC_CHR_BANK_4);
    fileClose(2);
    //memcpy (VIC_CHR_BANK_4, &buffer, sizeof(buffer));
}

int gameInit()
{
    playerReset();
}

#ifdef DEBUG
void debug()
{
        textcolor(1);
        gotoxy(0,24);   
        cprintf("x%03d y%03d d%03d %c",p.x,p.y,p.d,keyin);
}
#endif

/* initialize ui and game screen */
int screenInit()
{
    charsetLoad("wa");

    /* set colors */
    VIC.bordercolor = COLOR_BLACK;
    VIC.bgcolor0 = COLOR_GRAY1;
    VIC.bgcolor1 = COLOR_GRAY2;
    VIC.bgcolor2 = COLOR_GRAY3;
    VIC.ctrl2 |= MULTICOLOR;

    /* setup char and video ram */
    VIC.addr = 0x18;

    /* ..draw  */
    uiDraw();
}

/* End of hoc.h */
#endif