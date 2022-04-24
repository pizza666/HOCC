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
    switch(p.d)
    {
        case PD_NORTH:
            p.ico = PICO_NORTH;
            fov[W3] = map.data[p.y-3][p.x-1];
            fov[N3] = map.data[p.y-3][p.x];
            fov[E3] = map.data[p.y-3][p.x+1];
            fov[W2] = map.data[p.y-2][p.x-1];
            fov[N2] = map.data[p.y-2][p.x];
            fov[E2] = map.data[p.y-2][p.x+1];
            fov[W1] = map.data[p.y-1][p.x-1];
            fov[N1] = map.data[p.y-1][p.x];
            fov[E1] = map.data[p.y-1][p.x+1];
            fov[W0] = map.data[p.y][p.x-1];
            fov[E0] = map.data[p.y][p.x+1];
        break;
        case PD_SOUTH:
            p.ico = PICO_SOUTH;
            fov[W3] = map.data[p.y+3][p.x+1];
            fov[N3] = map.data[p.y+3][p.x];
            fov[E3] = map.data[p.y+3][p.x-1];
            fov[W2] = map.data[p.y+2][p.x+1];
            fov[N2] = map.data[p.y+2][p.x];
            fov[E2] = map.data[p.y+2][p.x-1];
            fov[W1] = map.data[p.y+1][p.x+1];
            fov[N1] = map.data[p.y+1][p.x];
            fov[E1] = map.data[p.y+1][p.x-1];
            fov[W0] = map.data[p.y][p.x+1];
            fov[E0] = map.data[p.y][p.x-1];
        break;
        case PD_EAST:
        	p.ico = PICO_EAST;
            fov[W1] = map.data[p.y-1][p.x+1];
            fov[W2] = map.data[p.y-1][p.x+2];
            fov[W3] = map.data[p.y-1][p.x+3];
            fov[E1] = map.data[p.y+1][p.x+1];
            fov[E2] = map.data[p.y+1][p.x+2];
            fov[E3] = map.data[p.y+1][p.x+3];
            fov[N1] = map.data[p.y][p.x+1];
            fov[N2] = map.data[p.y][p.x+2];
            fov[N3] = map.data[p.y][p.x+3];
            fov[W0] = map.data[p.y-1][p.x];
            fov[E0] = map.data[p.y+1][p.x];
        break;
        case PD_WEST:
            p.ico = PICO_WEST;
            fov[W1] = map.data[p.y+1][p.x-1];
            fov[W2] = map.data[p.y+1][p.x-2];
            fov[W3] = map.data[p.y+1][p.x-3];
            fov[E1] = map.data[p.y-1][p.x-1];
            fov[E2] = map.data[p.y-1][p.x-2];
            fov[E3] = map.data[p.y-1][p.x-3];
            fov[N1] = map.data[p.y][p.x-1];
            fov[N2] = map.data[p.y][p.x-2];
            fov[N3] = map.data[p.y][p.x-3];
            fov[W0] = map.data[p.y+1][p.x];
            fov[E0] = map.data[p.y-1][p.x];
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