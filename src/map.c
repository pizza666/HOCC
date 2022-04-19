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
#include <stdio.h>
#include "global.h"
#include "map.h"
#include "file.h"

void mapLoad(unsigned char mid)
{
    unsigned char f[4];
    sprintf(f,"m%03d",mid);
    fileOpen(f,2);
    fileRead(&map);
    fileClose(2);
}

void mapNext(){
    if(p.y==0) // player exits map north
    {
        mapLoad(map.meta[EXITN]);
        p.y=10;
    }
    if(p.y==MAPHEIGHT-1){
        mapLoad(map.meta[EXITS]);
        p.y=1;
    }
    if(p.x==0)
    {
        mapLoad(map.meta[EXITW]);
        p.x=MAPWIDTH;
    }
    if(p.x==MAPWIDTH-1)
    {
        mapLoad(map.meta[EXITE]);
        p.x=1;
    }
}

void mapDraw()
{
    int row=0;
    unsigned char i=0;
    int sp = 0;

    for(i=0;i<=MAPHEIGHT-1;++i)
    {
        memcpy(&MAPPOS_PTR[row], map.data[i],MAPWIDTH);
        if(i==p.y) MAPPOS_PTR[row+p.x] = p.ico;
        row +=SCREENWIDTH;
    }

}