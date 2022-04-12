/*********************************************************
 * canvas.h 
 *********************************************************
 * Main include for Halls of Curruption
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *********************************************************/

#ifndef _CANVAS_H
#define _CANVAS_H

/* wall defines */

/* horizon */
#define HO 0

/* last row of field of view */
#define W3 1
#define N3 2
#define E3 3

/* 2nd row infront of the fov */
#define W2 4
#define N2 5
#define E2 6

/* 1st row infront of the fov */
#define W1 7
#define N1 8
#define E1 9

/* left and right of the player */
#define W0 10
#define E0 11

#define POSX 0U
#define POSY 1U
#define WIDTH 2U
#define HEIGHT 3U

void canvasDrawWall(unsigned char wallNumber);
void canvasDrawHorizon();
void canvasLoad();
void copyWall(unsigned char *chars, unsigned char *color, unsigned char size, unsigned char wallNumber);

/* End of canvas.h */
#endif