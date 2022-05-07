/********************************************************
 * player.h 
 ********************************************************
 * Player structs and functions
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "entity.h"

#define PD_NORTH 0
#define PD_EAST  64
#define PD_SOUTH 128
#define PD_WEST  192

#define PICO_NORTH 28
#define PICO_EAST  PICO_NORTH+1
#define PICO_SOUTH PICO_NORTH+2
#define PICO_WEST  PICO_NORTH+3


typedef struct Player
{
    unsigned char x;
    unsigned char y;
    unsigned char d;
    unsigned char ico;
    Entity character;
} Player; 


unsigned char playerMove();
unsigned char playerAttack();
void playerReset();
void playerGetFov();

/* End of player.h */
#endif