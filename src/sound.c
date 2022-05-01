/********************************************************
 * sound.h
 ********************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "sound.h"

unsigned char volume = 12;

Sfx sfx[2] = {
    {2000,0,SID_WAVE_WHITENOISE,34,3},   // SFX_WALK
    {8000,0,SID_WAVE_WHITENOISE,34,3}   //SSFX_ATTACK
};

void soundPlaySfx(const unsigned char sfxId){
    SID.v1.ctrl = 0;
    SID.v1.ad = sfx[sfxId].ad;
    SID.v1.sr = sfx[sfxId].sr; 
    SID.v1.freq = sfx[sfxId].freq;
    SID.v1.ctrl = sfx[sfxId].ctrl;
}

void soundStop(){
    //SID.v1.ad = 0;
    //SID.v1.sr = 0;
    SID.v1.ctrl = 0;
}