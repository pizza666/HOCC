/********************************************************
 * skill.c
 * ******************************************************
 * <description> 
 * An RPG/dungeon crawler for C64 with pseudo 3D graphic
 * https://github.com/pizza666/HOCC by Jan-Dirk Lehde
 *******************************************************/

#include "menu.h"
#include "global.h"
#include "skill.h"

void skillDraw()
{
    menuLeftClr();
    cprintf("sp %d sl %d", p.character.skills[0].sp, p.character.skills[0].sl);
}

unsigned char skillGetSl(void* ent, unsigned char sp)
{
    Entity* e = ent;
    unsigned char sl=0;
    unsigned char i=0;
    unsigned char attr = e->attr.strDexInt[DEX];

    if(sp==0)
    {
        sl = attr-5;
        return sl;
    }
    else if (sp==1)
    {
        sl = attr-1;
        return sl;
    }
    else if (sp==2||sp==3)
    {
        sl = attr;
        return sl;
    }
    else if (sp>3)
    {
        sl = attr;
        while(sp>=4)
        {
            i++;
            sp-=4;
        }
        sl+=i;
    }
}