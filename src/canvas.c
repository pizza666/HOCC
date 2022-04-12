/********************************************************
 * canvas.c
 * ******************************************************
 * Functionality for drawing the gameview (canvas)
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <c64.h>
#include <string.h>
#include "global.h"
#include "file.h"
#include "canvas.h"


typedef struct CanvasData_T
{
    unsigned char n1_chars[208];
    unsigned char n1_color[208];
    unsigned char ho_chars[270];
    unsigned char ho_color[270];
} CanvasData;

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

CanvasData canvasData;

void copyWall(unsigned char *chars, unsigned char *color,unsigned char size,unsigned char wallNumber)
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

void canvasDrawWall(unsigned char wallNumber)
{
    switch(wallNumber)
    {
        case N1:
            copyWall(canvasData.n1_chars,canvasData.n1_color,sizeof(canvasData.n1_chars),N1);
            break;
        case HO:
            copyWall(canvasData.ho_chars,canvasData.ho_color,sizeof(canvasData.ho_chars),HO);
            break;
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

void canvasDrawHorizon()
{
}