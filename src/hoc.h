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

/* memory map and defines*/
#define SCREENRAM 0x0400
#define VIC_MEMSETUP 0xd018
#define VIC_CHR_BANK_4 0x2000
#define VIC_CHR_BANK_5 0x2800
#define SCREENSIZE 1000
#define LAST_USED_DEV 0xba
#define MULTICOLOR 16

unsigned char buffer[2048];
unsigned char st;
unsigned char keyin;
Player p;

unsigned char fileOpen(const char *filename, 
            unsigned char lfn)
{
    /* use last device */
    unsigned char dev;
    dev = (*(unsigned char*) LAST_USED_DEV);
    
    /* default it to 8 if its not set yet */
    if(dev==0)
    {
        dev = 8;
    }

    cbm_k_setnam(filename);
    cbm_k_setlfs(lfn,dev,lfn);
    st = cbm_k_open();
    cbm_k_chkin(lfn);

    return st;
};

/// read a file to given file  buffer array
unsigned char fileRead(unsigned char* fb)
{    
    st = 0;
    while(!(st)){
        
        *fb = cbm_k_chrin();
        fb++;
        st = cbm_k_readst();
    }
    return st;
}

void fileClose(unsigned char lfn)
{
    cbm_k_close(lfn);
};

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