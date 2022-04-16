/********************************************************
 * main.c
 * ******************************************************
 * Halls of Corruption  
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "global.h"
#include "hoc.h"
#include "input.h"
#include "map.h"

int main(void)
{
    clrscr();
    colorSetup();
    textcolor(1);
    mapLoad();
    cprintf("loading...");
    uiDraw();
    canvasLoad();
    screenInit();
    gameInit();

    playerGetFov();
    canvasDraw();
    mapDraw();

    while(1)
    {
        #ifdef DEBUG
            debug();
        #endif

        input();

        if(playerMove())
        {
            playerGetFov();
            canvasDraw();
        }

        mapDraw();
                
    }
    return 0;
}