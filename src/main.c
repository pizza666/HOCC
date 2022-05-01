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
#include "sprite.h"
#include "sound.h"


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
    spriteLoad();



    while(1)
    {
        #ifdef DEBUG
            debug();
        #endif

        input();

        if(playerAttack())
        {
            soundPlaySfx(SFX_ATTACK);
        }

        if(playerMove())
        {
            soundPlaySfx(SFX_WALK);
            mapNext();
            playerGetFov();
            canvasDraw();
            mapDraw();
        } 
    }
    return 0;
}