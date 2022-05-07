/*********************************************************
 * inventory.h 
 *********************************************************
 * <description>
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "item.h"

typedef struct Inventory
{
    struct Weapon* weapon;
} Inventory;

void inventoryDraw(void* inv);

#endif