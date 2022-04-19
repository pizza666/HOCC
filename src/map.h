/*********************************************************
 * map.h 
 *********************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _MAP_H
#define _MAP_H

#define W 175
#define _ 35

#define MAPPOS (SCREENRAM+0x8B)
#define MAPPOS_PTR ((unsigned char *) MAPPOS)
#define MAPHEIGHT 12
#define MAPWIDTH 20

#define MID 0
#define EXITN 1
#define EXITE 2
#define EXITS 3
#define EXITW 4
#define MCHR 5


typedef struct Map
{
    unsigned char meta[20];
    unsigned char data[12][20];
} Map;

void mapDraw();
void mapLoad();
void mapNext();


#endif