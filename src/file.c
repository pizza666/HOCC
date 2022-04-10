/*********************************************************
 * file.c
 *********************************************************
 * File handling
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 ********************************************************/

#include <cbm.h>
#include "global.h"
#include "file.h"

unsigned char st;

unsigned char fileOpen(const char *filename, 
            unsigned char lfn)
{
    /* use last device */
    unsigned char dev;
    dev = (*(unsigned char*) LAST_USED_DEV);
    
    /* default it to 8 if its not set yet */
    if(dev==0)
    {
        dev = 8;
    }

    cbm_k_setnam(filename);
    cbm_k_setlfs(lfn,dev,lfn);
    st = cbm_k_open();
    cbm_k_chkin(lfn);

    return st;
}

/// read a file to given file  buffer array
unsigned char fileRead(unsigned char* fb)
{    
    st = 0;
    while(!(st)){
        
        *fb = cbm_k_chrin();
        fb++;
        st = cbm_k_readst();
    }
    return st;
}

void fileClose(unsigned char lfn)
{
    cbm_k_close(lfn);
};