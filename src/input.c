/*********************************************************
 * hoc.h 
 *********************************************************
 * Main include for Halls of Curruption
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#include <conio.h>
#include <c64.h>
#include <joystick.h>
#include "global.h"
#include "input.h"

unsigned char joy;

void inputInit()
{
}

/* handle all inputs */
void input()
{
    if(kbhit)
        keyin = cgetc();
}