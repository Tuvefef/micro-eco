#include "rplayer.h"
#include "rcreature.h"

void RenderPlayer::moveCreature(CreatureCoord& crtr, SpaceCoords& space, vIntChar inc)
{
    if(std::holds_alternative<char>(inc))
    {
        char ginp = std::get<char>(inc);
        switch (ginp)
        {
            case 'w': crtr.gposy = gclamp(crtr.gposy - 1, 0, space.gwspace - 1);
                break;
            case 's': crtr.gposy = gclamp(crtr.gposy + 1, 0, space.ghspace - 1);
                break;
            case 'a': crtr.gposx = gclamp(crtr.gposx - 1, 0, space.gwspace - 1);
                break;
            case 'd': crtr.gposx = gclamp(crtr.gposx + 1, 0, space.ghspace - 1);
                break;
            case 'q': crtr.genergy = 0;
                break;
    
            default:
                 break;
        }
    }
}

void RenderPlayer::creatureEat(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space)
{
    RenderPrey spreys;
    if(crtr.gposx == npc.gposx &&  crtr.gposy == npc.gposy)
    {
        crtr.genergy += 10;
        spreys.creatureSpawn(crtr, npc, space);
    }
}

void RenderPlayer::playerLowenerg(CreatureCoord& crtr)
{
    crtr.genergy--;
}

bool RenderPlayer::playerDead(CreatureCoord& crtr)
{
    return crtr.genergy <= 0;
}