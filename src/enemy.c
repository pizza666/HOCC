/********************************************************
 * enemy.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include <string.h>
#include "global.h"
#include "enemy.h"
#include "sprite.h"

unsigned char encounter = 0;
Entity enemyCurrent;

Entity enemies[1] = {
    {"goblin",{{10,10,10},20,0,5}}
};

void enemySpawn(unsigned char enemyId)
{
    enemyCurrent = enemies[enemyId];
    encounter = 1;
    spriteDraw(3,ENEMY_SPRITE_1,75,100);
}

void enemyDespawn()
{
    memset(&enemyCurrent, 0, sizeof(Entity));
    spriteHide(ENEMY_SPRITE_1);
    encounter = 0;
}