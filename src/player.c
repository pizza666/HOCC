/********************************************************
 * player.c
 ********************************************************
 * Player functionality
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "global.h"
#include "player.h"

void playerReset()
{
    p.x = 0;
    p.y = 0;
    p.d = 0;
}

void playerMove()
{
    switch(keyin)
    {
        case 'q':
            p.d -= 64;
            break;
        case 'e':
            p.d += 64;
            break;
        case 'w':
            switch (p.d)
            {
                case PD_NORTH: p.y--; break;
                case PD_EAST : p.x++; break;
                case PD_SOUTH: p.y++; break;
                case PD_WEST : p.x--; break;
            }
            break;
        case 's':
            switch(p.d)
            {
                case PD_NORTH: p.y++; break;
                case PD_EAST : p.x--; break;
                case PD_SOUTH: p.y--; break;
                case PD_WEST : p.x++; break;
            }
            break;
        case 'a':
            switch (p.d)
            {
                case PD_NORTH: p.x--; break;
                case PD_EAST : p.y--; break;
                case PD_SOUTH: p.x++; break;
                case PD_WEST : p.y++; break;
                break;
            }
            break;
        case 'd':
            switch(p.d)
            {
                case PD_NORTH: p.x++; break;
                case PD_EAST : p.y++; break;
                case PD_SOUTH: p.x--; break;
                case PD_WEST : p.y--; break;
                break;
            }
            break;
    }
};