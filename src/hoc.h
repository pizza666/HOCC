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
#include <peekpoke.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* enable debugging */
#define DEBUG

/* custom includes */
// #include "global.h"
//#include "input.h"
//#include "player.h"
// #include "file.h"
//#include "canvas.h"

void uiDraw();
void charsetLoad(const char *filename);
void gameInit();
void screenInit();

#ifdef DEBUG
void debug();
#endif

/* End of hoc.h */
#endif