/********************************************************
 * sprite.c
 * ******************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/
#include <c64.h>
#include "global.h"
#include "file.h"
#include "sprite.h"

unsigned char sprBitmask[8] = {
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b10000000,
};

void spriteLoad()
{

    fileOpen("s001",2);
    fileRead(SPRITE.data);
    fileClose(2);

    VIC.spr_mcolor = 0xFF;
    VIC.spr_mcolor0 = COLOR_WHITE;
    VIC.spr_mcolor1 = COLOR_GRAY3;
}

/// points sprPtr to the sprId (from SPRITE.data)
/// and draws the sprite to x and y position
/// the 64th byte contains SpritePad flags



void spriteDraw(unsigned char sprId, unsigned char sprPtr, unsigned char x, unsigned char y)
{
    SPRITE.ptr[sprPtr] = SPR_PTR+sprId;

    VIC.spr_ena |= sprBitmask[sprPtr];
    VIC.spr_color[sprPtr] = SPRITE.data[sprId][SPRATTR];
    VIC.spr_pos[sprPtr].x = x;
    VIC.spr_pos[sprPtr].y = y;

    // else 
    //     VIC.spr_exp_y |= exp_0;
    if((SPRITE.data[sprId][SPRATTR] & SPRITE_FLAG_EXP_X))
         VIC.spr_exp_x |= sprBitmask[sprPtr];
    if((SPRITE.data[sprId][SPRATTR] & SPRITE_FLAG_EXP_Y))
         VIC.spr_exp_y |= sprBitmask[sprPtr];
    // else
    //     VIC.spr_exp_x |= exp_0;

}

void spriteHide(unsigned char sprPtr)
{
    VIC.spr_ena &= ~sprBitmask[sprPtr];
}