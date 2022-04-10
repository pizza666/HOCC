/********************************************************
 * hoc.c
 * ******************************************************
 * Halls of Corruption  
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "hoc.h"

int main(void)
{
    screenInit();
    gameInit();
    
    while(1)
    {
        #ifdef DEBUG
            debug();
        #endif

        input();
        playerMove();
    }
    return 0;
}