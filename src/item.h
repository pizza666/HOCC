/*********************************************************
 * item.h 
 *********************************************************
 * <description>
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _ITEM_H
#define _ITEM_H

#define ITEM_AXE 0
#define ITEM_MACE 1

#define WEAPON_SPRITE_1 0

typedef struct Weapon
{
    unsigned char name[10];
    unsigned char dmgMin;
    unsigned char dmgMax;
    unsigned char skillId;
} Weapon;

#endif