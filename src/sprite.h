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

                                    // flags:
#define SPRITE_FLAG_MC          128 // 1000----
#define SPRITE_FLAG_EXP_Y        64 // 0100----
#define SPRITE_FLAG_EXP_X        32 // 0010----
#define SPRITE_FLAG_OVERLAY      16 // 0001----
                                    // color:
                                    // ----xxxx

#define SPRITE (*(struct __sprite*) SPRITE_PTR)

#define SPRITE_DATA_COUNT 2
#define SPRITE_DATA_UNCOMPRESSED_SIZE (SPRITE_DATA_COUNT*64)

struct __sprite
{
    unsigned char ptr[8];
    unsigned char data[16][64];
};

void spriteLoad();
void spriteDraw(unsigned char sprId, unsigned char sprPtr, unsigned char x, unsigned char y);
void spriteHide(unsigned char sprPtr);

#endif