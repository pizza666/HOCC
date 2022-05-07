/********************************************************
 * inventory.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "inventory.h"
#include "menu.h"

void inventoryDraw(void* inventory)
{
    Inventory* inv = inventory;

    menuLeftClr();
    cprintf("w: %s dmg: %dd%d", inv->weapon->name, inv->weapon->dmgMin,inv->weapon->dmgMax);
}
