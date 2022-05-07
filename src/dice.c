/********************************************************
 * dice.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <stdlib.h>
#include <conio.h>
#include "global.h"
#include "dice.h"

/// returns a D6 roll
// unsigned char diceRollD6()
// {
//     //unsigned char d6 = (rand() % 6 + 1);
//     return (rand() % 6 + 1);;
// }

unsigned char diceRoll(unsigned char dice)
{
    return (rand() % dice + 1);
}

/// checks sl against 3D6
/// returns 0 if unsuccessful 1 if 
unsigned char diceRollSuccess(unsigned char sl)
{
    unsigned char d1 = diceRoll(D6);
    unsigned char d2 = diceRoll(D6);
    unsigned char d3 = diceRoll(D6);
    unsigned char sum = d1+d2+d3;

    #ifdef DEBUG
        gotoxy(2,18);   
        cprintf("d1: %03d d2: %03d d3: %03d s: %03d",d1,d2,d3,sum);
    #endif

    if(sum<=sl) return SUCCESS;
    else return FAIL;
}