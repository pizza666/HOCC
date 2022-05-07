#ifndef _SKILL_H
#define _SKILL_H

#include "entity.h"

typedef struct Skill
{
    unsigned char name;
    unsigned char sl;
    unsigned char sp;
    unsigned char attr;
} Skill;

void skillDraw();
unsigned char skillGetSl(void* ent, unsigned char sp);

#endif