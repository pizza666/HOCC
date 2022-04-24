/********************************************************
 * sprite.c
 * ******************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/
#include <c64.h>
#include "global.h"
#include "file.h"
#include "sprite.h"



void spriteLoad()
{
    unsigned char i = 1;

    fileOpen("s001",2);
    fileRead(SPRITE.data);
    fileClose(2);


    SPRITE.ptr[0] = SPR_PTR+i;

    VIC.spr_ena = 1;
    VIC.spr_color[0] = SPRITE.data[i][SPRATTR];
    VIC.spr0_x = SPRITE_WEAPON_X;
    VIC.spr0_y = SPRITE_WEAPON_Y;
    VIC.spr_mcolor = 0xFF;
    VIC.spr_exp_y = 1;

    VIC.spr_mcolor0 = COLOR_WHITE;
    VIC.spr_mcolor1 = COLOR_GRAY3;
}