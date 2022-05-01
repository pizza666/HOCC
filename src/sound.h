/********************************************************
 * sound.h 
 ********************************************************
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#ifndef _SOUND_H
#define _SOUND_H

#include <c64.h>
#include <_sid.h>

// wave forms

#define SID_WAVE_WHITENOISE 129


/// sound effects
#define SFX_WALK 0
#define SFX_ATTACK 1

typedef struct __sid_voice Sfx;

void soundPlaySfx(const unsigned char sfxId);
void soundStop();

#endif