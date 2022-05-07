#ifndef _ENTITY_H
#define _ENTITY_H

#include "skill.h"
#include "attr.h"
#include "inventory.h"


#define ENTITY_MAX_SKILLS 10
#define ENTITY_NAME_LEN 8

typedef struct Entity
{
    unsigned char name[ENTITY_NAME_LEN];
    struct Attr attr;
    struct Skill skills[ENTITY_MAX_SKILLS];
    struct Inventory inventory; 
} Entity;

#endif