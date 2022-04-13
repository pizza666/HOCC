/********************************************************
 * canvas.c
 * ******************************************************
 * Functionality for drawing the gameview (canvas)
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <c64.h>
#include <string.h>
#include "global.h"
#include "canvas.h"
#include "file.h"

const unsigned char meta[12][4] = {
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15},
    {1,1,16,13},
    {0,0,18,15},
    {0,0,18,15},
    {0,0,18,15}
};

void copyWall(const unsigned char *chars, const unsigned char *color, const unsigned char size, const unsigned char wallNumber)
{
    unsigned char i = 0;
    unsigned char row = 0;
    int sp = (SCREENWIDTH*meta[wallNumber][POSY]) + meta[wallNumber][POSX];
    
    for(i=0;i<=meta[wallNumber][HEIGHT]-1;++i)
    {
        memcpy(SCREENRAM+sp,chars+row,meta[wallNumber][WIDTH]);
        memcpy(COLOR_RAM+sp,color+row,meta[wallNumber][WIDTH]);
        sp += SCREENWIDTH;
        row += meta[wallNumber][WIDTH];
    }
}

void canvasLoad()
{
    /* we should load whole "tilesets" in the future from a single file*/
    fileOpen("n1",2);
    fileRead(canvasData.n1_chars);
    fileClose(2);

    fileOpen("ho",2);
    fileRead(canvasData.ho_chars);
    fileClose(2);
}