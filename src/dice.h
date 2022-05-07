/*********************************************************
 * dice.h 
 *********************************************************
 * Roll some dices
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _DICE_H
#define _DICE_H

#define FAIL 0
#define SUCCESS 1

#define D100    100
#define D20     20
#define D6      6
#define D4      4

// unsigned char diceRollD6();
unsigned char diceRoll(unsigned char dice);
#endif
