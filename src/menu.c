/********************************************************
 * menu.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "menu.h"

/// clears the left menu and set cursor 
/// to the top left of the menu area
void menuLeftClr()
{
    unsigned char i=0;
    textcolor(0);
    for(i;i<LEFT_MENU_HEIGHT;++i)
    {
        chlinexy(LEFT_MENU_X,LEFT_MENU_Y+i,LEFT_MENU_WIDTH);
    }
    gotoxy(20,4);
}