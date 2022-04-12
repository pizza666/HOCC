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
    canvasLoad();
    
    while(1)
    {
        #ifdef DEBUG
           debug();
        #endif

        input();
        playerMove();
        if(keyin=='1') canvasDrawWall(N1);
        if(keyin=='2') canvasDrawWall(HO);
                
    }
    return 0;
}