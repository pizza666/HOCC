/********************************************************
 * player.h 
 ********************************************************
 * Player structs and functions
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _PLAYER_H
#define _PLAYER_H

#define PD_NORTH 0
#define PD_EAST  64
#define PD_SOUTH 128
#define PD_WEST  192

static struct Player
{
    unsigned char x;
    unsigned char y;
    unsigned char d;
}; 

typedef struct Player Player;

void playerMove();
void playerReset();

/* End of player.h */
#endif