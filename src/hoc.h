/*********************************************************
 * hoc.h 
 *********************************************************
 * Main include for Halls of Curruption
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _HOC_H
#define _HOC_H

/* std includes */
#include <cbm.h>
#include <c64.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/* game specific consts */

#define SPAWN_RATE 4

void uiDraw();
void charsetLoad(const char *filename);
void gameInit();
void screenInit();
void clearScreen();
void colorSetup();
void vicSetup();

#ifdef DEBUG
void debug();
#endif

/* End of hoc.h */
#endif