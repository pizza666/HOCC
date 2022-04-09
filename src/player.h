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
} p = {0,0,0}; 

typedef struct Player Player;

// Player *p;

// Player* playerNew()
// {   
//     Player *p = malloc(sizeof(Player));

//     return p;
// }

// void playerMove(Player *p, unsigned char keyin)
// {
//     // switch(keyin)
//     // {
//     //     case 'q':
//     //         p->d -= 64;
//     //         break;
//     //     case 'e':
//     //         p->d += 64;
//     //         break;
//     //     case 'w':
//     //         switch (p->d)
//     //         {
//     //             case PD_NORTH: p->y--; break;
//     //             case PD_EAST : p->x++; break;
//     //             case PD_SOUTH: p->y++; break;
//     //             case PD_WEST : p->x--; break;
//     //         }
//     //         break;
//     //     case 's':
//     //         switch(p->d)
//     //         {
//     //             case PD_NORTH: p->y++; break;
//     //             case PD_EAST : p->x--; break;
//     //             case PD_SOUTH: p->y--; break;
//     //             case PD_WEST : p->x++; break;
//     //         }
//     //         break;
//     //     // case 'a':
//     //     //     if(p->d==PD_NORTH) p->x--;
//     //     //     if(p->d==PD_EAST ) p->y--;
//     //     //     if(p->d==PD_SOUTH) p->x++;
//     //     //     if(p->d==PD_WEST ) p->y++;
//     //     //     break;
//     //     // case 'd':
//     //     //     if(p->d==PD_NORTH) p->x++;
//     //     //     if(p->d==PD_EAST ) p->y++;
//     //     //     if(p->d==PD_SOUTH) p->x--;
//     //     //     if(p->d==PD_WEST ) p->y--;
//     //     //     break;
//     // }
// };

/* End of player.h */
#endif