/********************************************************
 * canvas.c
 * ******************************************************
 * Functionality for drawing the gameview (canvas)
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <c64.h>
#include <string.h>
#include <lz4.h>
#include "global.h"
#include "canvas.h"
#include "file.h"

const unsigned char meta[13][4] = {
    {0,0,18,15},  // HO 0 
    {0,6,6,3},    // W3 1 
    {12,6,6,3},    // E3 2
    {6,6,6,3},   // N3 3
    {0,4,6,7},    // W2 4
    {12,4,6,7},   // E2 5
    {4,4,10,7},   // N2 6
    {0,1,4,13},   // W1 7
    {14,1,4,13},  // E1 8
    {1,1,16,13},  // N1 9
    {0,0,1,15},   // W0 10
    {17,0,1,15},   // E0 11
    {0,0,18,15}   // buffer
};

const int wallDataOffsets[12] = {
    0x0000,    // HO 0 
    0x0264,    // W3 1
    0x0258,    // E3 2
    0x025E,    // N3 3
    0x02D0,    // W2 4
    0x02D6,    // E2 5
    0x02DC,    // N2 6
    0x01FE,    // W1 7
    0x0202,    // E1 8
    0x0000,    // N1 9
    0x0010,    // W0 10
    0x0011     // E0 11
};

unsigned char canvasCharsBuffer[600];
unsigned char canvasColorBuffer[600];

void canvaseWallToBuffer(const unsigned char wallNumber)
{
    unsigned char i=0;
    int row = wallDataOffsets[wallNumber];
    int sp = (SCREENWIDTH*meta[wallNumber][POSY]) + meta[wallNumber][POSX];
    
    for(i;i<=meta[wallNumber][HEIGHT]-1;++i)
    {
        memcpy(&canvasCharsBuffer[sp],&buffer[row],meta[wallNumber][WIDTH]);
        memcpy(&canvasColorBuffer[sp],&buffer[SCREENSIZE+row],meta[wallNumber][WIDTH]);
        sp += SCREENWIDTH;
        row += SCREENWIDTH;
    }
}

void canvasDraw()
{
    unsigned char i = 0;
    int row = 0;
    int sp = 0;

    //canvasHorizonDraw();
    for(i;i<=14;++i)
    {
        memcpy(&canvasCharsBuffer[sp],&ui[row],meta[HO][WIDTH]);
        memcpy(&canvasColorBuffer[sp],&ui[SCREENSIZE+row],meta[HO][WIDTH]);
        sp += SCREENWIDTH;
        row += SCREENWIDTH;
    }

    for(i=1;i<=12;++i)
    {
        if(fov[i]==W) canvaseWallToBuffer(i);
    }
    
    sp = 0;
    row = 0;

    for(i=0;i<=14;++i)
    {
        memcpy(SCREENRAM_PTR+sp,&canvasCharsBuffer[row],18);
        memcpy(COLOR_RAM+sp,&canvasColorBuffer[row],18);
        sp += SCREENWIDTH;
        row += SCREENWIDTH;
    }
}

void canvasLoad()
{
    /* change this to match the tileset of map data later */
    fileOpen("d000lz",2);
    fileRead(lzbuffer);
    fileClose(2);
    decompress_lz4(lzbuffer+8, buffer, 2000);
}
