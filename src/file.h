/*********************************************************
 * file.h 
 *********************************************************
 * File handling include
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#ifndef _FILE_H
#define _FILE_H

#define LAST_USED_DEV 0xba

extern unsigned char st;

unsigned char fileOpen(const char *filename, unsigned char lfn);
unsigned char fileRead(unsigned char* fb);
void fileClose(unsigned char lfn);

/* end of file.h */
#endif