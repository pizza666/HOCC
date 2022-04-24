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
    screenInit();

    clrscr();
    colorSetup();
    textcolor(1);
    mapLoad(0);
    cprintf("loading");
    uiDraw();
    canvasLoad();
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
            mapNext();
            playerGetFov();
            canvasDraw();
            mapDraw();
        }
        keyin = 0;            
    }
    return 0;
}