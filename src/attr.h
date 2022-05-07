#ifndef _ATTR_H
#define _ATTR_H

#define STR 0
#define DEX 1
#define INT 2

typedef struct Attr
{
    unsigned char strDexInt[3];
    unsigned char hp; // we have to see if
    unsigned char mp; // we need int 
    unsigned char ac; // for some of theses
} Attr;

#endif