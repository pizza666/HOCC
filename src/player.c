/********************************************************
 * player.c
 ********************************************************
 * Player functionality
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "global.h"
#include "player.h"
#include "canvas.h"

void playerReset()
{
    p.x = 1;
    p.y = 8;
    p.d = 0;
}

void playerGetFov()
{
    unsigned char i;
    unsigned char j;
    switch(p.d)
    {
        case PD_NORTH:
            p.ico = PICO_NORTH;
            j = 3;
            for(i=1;i<12;i+=3)
            {
                fov[i] =  map.data[p.y-j][p.x-1];
                fov[i+1] = map.data[p.y-j][p.x+1];
                fov[i+2] = map.data[p.y-j][p.x];
                j--;
            }
        break;
        case PD_SOUTH:
            p.ico = PICO_SOUTH;
            j = 3;
            for(i=1;i<12;i+=3)
            {
                fov[i] =  map.data[p.y+j][p.x+1];
                fov[i+1] = map.data[p.y+j][p.x-1];
                fov[i+2] = map.data[p.y+j][p.x];
                j--;
            }
        break;
        case PD_EAST:
        	p.ico = PICO_EAST;
            j = 3;
            for(i=1;i<12;i+=3)
            {
                fov[i] =  map.data[p.y-1][p.x+j];
                fov[i+1] = map.data[p.y+1][p.x+j];
                fov[i+2] = map.data[p.y][p.x+j];
                j--;
            }
        break;
        case PD_WEST:
            p.ico = PICO_WEST;

            j = 3;
            for(i=1;i<12;i+=3)
            {
                fov[i] =  map.data[p.y+1][p.x-j];
                fov[i+1] = map.data[p.y-1][p.x-j];
                fov[i+2] = map.data[p.y][p.x-j];
                j--;
            }
        break;
    }
}

/// player movement function with collision detection on walls
unsigned char playerMove()
{
    switch(keyin)
    {
        case 'q':
            p.d -= 64;
            return 1;
        break;
        case 'e':
            p.d += 64;
            return 1;
        break;
        case 'w':
            switch (p.d)
            {
                case PD_NORTH: if(map.data[p.y-1][p.x] !=W) {p.y--; return 1;} break;
                case PD_EAST : if(map.data[p.y][p.x+1] !=W) {p.x++; return 1;} break;
                case PD_SOUTH: if(map.data[p.y+1][p.x] !=W) {p.y++; return 1;} break;
                case PD_WEST : if(map.data[p.y][p.x-1] !=W) {p.x--; return 1;} break;
            }
            break;
        case 's':
            switch(p.d)
            {
                case PD_NORTH: if(map.data[p.y+1][p.x] !=W) {p.y++; return 1;} break;
                case PD_EAST : if(map.data[p.y][p.x-1] !=W) {p.x--; return 1;} break;
                case PD_SOUTH: if(map.data[p.y-1][p.x] !=W) {p.y--; return 1;} break;
                case PD_WEST : if(map.data[p.y][p.x+1] !=W) {p.x++; return 1;} break;
            }
            break;
        case 'a':
            switch (p.d)
            {
                case PD_NORTH: if(map.data[p.y][p.x-1] !=W) {p.x--; return 1;} break;
                case PD_EAST : if(map.data[p.y-1][p.x] !=W) {p.y--; return 1;} break;
                case PD_SOUTH: if(map.data[p.y][p.x+1] !=W) {p.x++; return 1;} break;
                case PD_WEST : if(map.data[p.y+1][p.x] !=W) {p.y++; return 1;} break;
                break;
            }
            break;
        case 'd':
            switch(p.d)
            {
                case PD_NORTH: if(map.data[p.y][p.x+1] !=W) {p.x++; return 1; } break;
                case PD_EAST : if(map.data[p.y+1][p.x] !=W) {p.y++; return 1; } break;
                case PD_SOUTH: if(map.data[p.y][p.x-1] !=W) {p.x--; return 1; } break;
                case PD_WEST : if(map.data[p.y-1][p.x] !=W) {p.y--; return 1; } break;
                break;
            }
            break;
    }
    return 0; // player hasn't moved
}

unsigned char playerAttack(){
    if(keyin==' ')
    {
        return 1;
    }
}