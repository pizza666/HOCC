/********************************************************
 * sprite.h
 * ******************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _SPRITE_H
#define _SPRITE_H

#define SPRITE_PTR          ((unsigned char *) SCREENRAM+0x03F8)
#define SPRITERAM           ((unsigned char*) SCREENRAM+SPRITE_DATA_OFFSET)
#define SPRITE_DATA_OFFSET  0x0400
#define SPRITE_ATTR         ((unsigned char *) SCREENRAM+1000)

#define SPR_PTR             (SPRITE_DATA_OFFSET/64)
#define SPRATTR             63

#define SPRITE_WEAPON_X     140
#define SPRITE_WEAPON_Y     128

#define SPRITE (*(struct __sprite*) SPRITE_PTR)

struct __sprite
{
    unsigned char ptr[8];
    unsigned char data[16][64];
};

void spriteLoad();

#endif