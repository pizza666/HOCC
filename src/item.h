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

typedef struct Weapon
{
    unsigned char name[10];
    unsigned char dmg;
    unsigned char skillId;
} Weapon;

#endif