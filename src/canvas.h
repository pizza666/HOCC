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

typedef struct CanvasData
{
    unsigned char n1_chars[208];
    unsigned char n1_color[208];
    unsigned char ho_chars[270];
    unsigned char ho_color[270];
} CanvasData;

void canvasLoad();
void copyWall(const unsigned char *chars, const unsigned char *color, const unsigned char size, const unsigned char wallNumber);

/* End of canvas.h */
#endif