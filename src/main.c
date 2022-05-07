/********************************************************
 * main.c
 * ******************************************************
 * Halls of Corruption  
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "global.h"
#include "hoc.h"
#include "input.h"
#include "map.h"
#include "sprite.h"
#include "sound.h"
#include "menu.h"
#include "dice.h"
#include "enemy.h"


int main(void)
{
    unsigned char a = 0;
    int i=0;

    screenInit();
    clrscr();
    colorSetup();
    textcolor(1);
    cprintf("loading");
    mapLoad(0);
    SCREENRAM_PTR[7] = '.';
    canvasLoad();
    SCREENRAM_PTR[8] = '.';
    spriteLoad();
    SCREENRAM_PTR[9] = '.';
    uiDraw();
    gameInit();
    playerGetFov();
    canvasDraw();

    while(1)
    {
        #ifdef DEBUG
            debug();
        #endif

        input();

        if(keyin == '+'){

            p.character.skills[0].sp++;
            p.character.skills[0].sl = skillGetSl(&p.character, p.character.skills[0].sp);  
            skillDraw();          
        }
        if(keyin == '-')
        {
            p.character.skills[0].sp--;
            p.character.skills[0].sl = skillGetSl(&p.character, p.character.skills[0].sp);     
            skillDraw();  
        }

        if(keyin=='m')
        {
            mapDraw();
        }

        if(keyin=='k')
        {
            skillDraw();
        }

        if(keyin=='i')
        {
            inventoryDraw(&p.character.inventory);
        }

        if(keyin=='6')
        {
           d6 =  diceRoll(D6);
        }

        if(keyin=='r')
        {
            // draw weapon
            if(VIC.spr_ena & sprBitmask[WEAPON_SPRITE_1])
                spriteHide(WEAPON_SPRITE_1);
            else
                spriteDraw(ITEM_AXE,WEAPON_SPRITE_1,SPRITE_WEAPON_X,SPRITE_WEAPON_Y);
        }

        if(!encounter && playerMove())
        {
            soundPlaySfx(SFX_WALK);
            mapNext();
            playerGetFov();
            canvasDraw();

            // simulate spawn with a fixed spawnrate
            if(diceRoll(D100)<SPAWN_RATE&&fov[N1]!=W)
            {
                enemySpawn(ENEMY_GOBLIN);
            }
        } 

        if(encounter)
        {
            // testing attack routine here

            if(keyin==' ') {
                soundPlaySfx(SFX_ATTACK);      
                d20 = diceRoll(D20);
                if(d20>enemyCurrent.attr.ac)
                {
                    d6 = diceRoll(p.character.inventory.weapon->dmgMax);
                    if(enemyCurrent.attr.hp>d6)
                        enemyCurrent.attr.hp -= d6;
                    else enemyCurrent.attr.hp=0;
                }
            
                // is it dead yet?
                if(enemyCurrent.attr.hp<=0)
                {
                    enemyDespawn();
                }
            }


        }
        
        // reset input
        keyin=0;
    }
    return 0;
}