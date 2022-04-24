/********************************************************
 * input.h 
 ********************************************************
 * Input functions
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _INPUT_H
#define _INPUT_H

/* keybard layout */
#define KEY_MAP 'm'
#define KEY_MOVE_FORWARD 'w'
#define KEY_MOVE_BACKWARDS 's'
#define KEY_MOVE_LEFT 'a'
#define KEY_MOVE_RIGHT 'd'
#define KEY_ROTATE_LEFT 'q'
#define KEY_ROTATE_RIGHT 'e'

void inputInit();
void input();

/* end of input.h */
#endif