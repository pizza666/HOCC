/********************************************************
 * hoc.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/
#include <string.h>
#include "global.h"
#include "hoc.h"
#include "file.h"
#include "map.h"

unsigned char ui[2000];
unsigned char buffer[2000];
unsigned char keyin;
unsigned char fov[11];
Player p;
Map map;

void uiDraw()
{
    // load ui charmap
    fileOpen("ui",2);
    fileRead(ui);
    fileClose(2);
    memcpy(SCREENRAM_PTR, &ui, SCREENSIZE);        // chars 
    memcpy(COLOR_RAM, &ui[SCREENSIZE], SCREENSIZE);  // color
}

void charsetLoad(const char *filename)
{
    // load charset
    fileOpen(filename,2); 
    fileRead(VIC_CHR_BANK);
    fileClose(2);
}

void gameInit()
{
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
void screenInit()
{
    charsetLoad("wa");
    colorSetup();
    vicSetup();
}

void vicSetup()
{
    /* setup char and video ram */
    VIC.addr = 0b00000011;
    CIA2.pra &= 0b11111100;
    *(unsigned char*) SCREEN_RAM_HI_PTR = SCREENRAM_HI;
}

void colorSetup()
{
    /* set colors */
    VIC.bordercolor = COLOR_BLACK;
    VIC.bgcolor0 = COLOR_GRAY1;
    VIC.bgcolor1 = COLOR_GRAY2;
    VIC.bgcolor2 = COLOR_GRAY3;
    VIC.ctrl2 |= MULTICOLOR;
}