/********************************************************
 * map.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <string.h>
#include <conio.h>
#include <c64.h>
#include "global.h"
#include "map.h"
#include "file.h"

void mapLoad()
{
    int i = 0;
    playerReset();
    fileOpen("m0",2);
    fileRead(&(map.data));
    fileClose(2);
}

void mapDraw()
{
    int row=0;
    unsigned char i=0;
    int sp = 0;

    for(i=0;i<=MAPHEIGHT-1;++i)
    {
        memcpy(MAPPOS+row, map.data[i],MAPWIDTH);
        row +=SCREENWIDTH;
    }

    gotoxy(19+p.x,3+p.y);
    textcolor(COLOR_BLACK);
    cputc(p.ico);

}