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
#define MAPHEIGHT 12
#define MAPWIDTH 20

typedef struct Map
{
    unsigned char data[12][20];
} Map;

void mapDraw();
void mapLoad();


#endif