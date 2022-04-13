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

int main(void)
{
    screenInit();
    gameInit();
    canvasLoad();
    uiDraw();
    
    while(1)
    {
        #ifdef DEBUG
            debug();
        #endif

        input();
        playerMove();
        if(keyin=='1') copyWall(canvasData.n1_chars,canvasData.n1_color,sizeof(canvasData.n1_chars),N1);
        if(keyin=='2') copyWall(canvasData.ho_chars,canvasData.ho_color,sizeof(canvasData.ho_chars),HO);
                
    }
    return 0;
}