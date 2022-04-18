/*********************************************************
 * canvas.h 
 *********************************************************
 * Main include for Halls of Corruption
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *********************************************************/

#ifndef _CANVAS_H
#define _CANVAS_H

/* wall defines */

/* horizon */
#define HO 0

/* last row of field of view */
#define W3 1
#define E3 2
#define N3 3


/* 2nd row infront of the fov */
#define W2 4
#define E2 5
#define N2 6


/* 1st row infront of the fov */
#define W1 7
#define E1 8
#define N1 9

/* left and right of the player */
#define W0 10
#define E0 11

#define POSX 0U
#define POSY 1U
#define WIDTH 2U
#define HEIGHT 3U
   
void canvasLoad();
void canvasDraw();
// void canvasWallDraw(const unsigned char wallNumber);
void canvaseWallToBuffer(const unsigned char wallNumber);
void canvasTilesetLoad();
// void canvasHorizonDraw();
// void copyWall();


/* End of canvas.h */
#endif