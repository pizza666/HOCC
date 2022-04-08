/***
 * hoc.h 
 * *******************************************
 * Main include for Halls of Curruption
 * https://github.com/pizza666 Jan-Dirk Lehde
 * 
 ********************************************/

#include <cbm.h>
#include <c64.h>
#include <conio.h>
#include <peekpoke.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _HOC_H
#define _HOC_H

// mem map
#define SCREENRAM 0x0400
#define VIC_MEMSETUP 0xd018
#define VIC_CHR_BANK_4 0x2000
#define VIC_CHR_BANK_5 0x2800
#define SCREENSIZE 1000
#define LAST_USED_DEV 0xba
#define MULTICOLOR 16;

unsigned char buffer[2048];

int openFile(unsigned char *filename, 
            unsigned char lfn)
{
    // use last device
    unsigned char dev;
    dev = (*(unsigned char*) LAST_USED_DEV);
    
    // default it to 8 if its not set yet
    if(dev==0)
    {
        dev = 8;
    }

    cbm_k_setnam(filename);
    cbm_k_setlfs(lfn,dev,lfn);
    cbm_k_open();
    cbm_k_chkin(lfn);
};

/// read a file to given file  buffer array
int readFile(unsigned char* fb)
{    
    unsigned char st = 0;
    while(!(st)){
        
        *fb = cbm_k_chrin();
        fb++;
        st = cbm_k_readst();
    }
}

int closeFile(unsigned char lfn)
{
    cbm_k_close(lfn);
};

int drawUi()
{

    // load ui charmap
    openFile("ui",2);
    readFile(&buffer);
    closeFile(2);
    memcpy(SCREENRAM, &buffer, SCREENSIZE);        // chars 
    memcpy(COLOR_RAM, &buffer[SCREENSIZE], SCREENSIZE);  // color
};

int loadCharset(const char *filename)
{
    // load charset
    openFile(filename,2); 
    readFile(VIC_CHR_BANK_4);
    closeFile(2);
    //memcpy (VIC_CHR_BANK_4, &buffer, sizeof(buffer));

};

/// initilize ui and game screen
int initScreen()
{
    loadCharset("wa");

    // set colors
    VIC.bordercolor = COLOR_BLACK;
    VIC.bgcolor0 = COLOR_GRAY1;
    VIC.bgcolor1 = COLOR_GRAY2;
    VIC.bgcolor2 = COLOR_GRAY3;
    VIC.ctrl2 |= MULTICOLOR;

    // setup char and video ram
    VIC.addr = 0x18;

    // ..draw    
    drawUi();
};

// End of hoc.h
#endif