#include "creature.h"
#include "structs.h"

void RenderCreature::renderPlayermove(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space, char ginp)
{

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

void RenderCreature::creaturealowenerg(CreatureCoord& crtr)
{
    crtr.genergy--;
}

bool RenderCreature::creatureDead(CreatureCoord& crtr)
{
    return crtr.genergy <= 0;
}

void RenderCreature::preyCreature(CreatureCoord& npc, SpaceCoords& space)
{
    int gprei = rand() % 6;
    switch (gprei)
    {
    case 0: npc.gposy = gclamp(npc.gposy - 1, 0, space.gwspace - 1);
        break;
    case 1: npc.gposy = gclamp(npc.gposy + 1, 0, space.ghspace - 1);
        break;
    case 2: npc.gposx = gclamp(npc.gposx - 1, 0, space.gwspace - 1);
        break;
    case 3: npc.gposx = gclamp(npc.gposx + 1, 0, space.ghspace - 1);
        break;
    
    default:
        break;
    }
}

void RenderCreature::spawnPrey(CreatureCoord& npc, CreatureCoord& crtr, SpaceCoords& space)
{
    do
    {
        npc.gposx = rand() % space.gwspace;
        npc.gposy = rand() % space.ghspace;
    } while (npc.gposx == crtr.gposx && npc.gposy == crtr.gposy);
}

void RenderCreature::eatPrey(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space)
{
    if(crtr.gposx == npc.gposx &&  crtr.gposy == npc.gposy)
    {
        crtr.genergy += 10;
        spawnPrey(npc, crtr, space);
    }
}

void RenderCreature::predatorCreature(CreatureCoord& predatorCreature, SpaceCoords& space)
{
    int gpr = rand() % 4;

    switch(gpr)
    {
        case 0: predatorCreature.gposy = gclamp(predatorCreature.gposy - 1, 0, space.gwspace -1);
            break;
        case 1: predatorCreature.gposy = gclamp(predatorCreature.gposy + 1, 0, space.ghspace - 1);
            break;
        case 2: predatorCreature.gposx = gclamp(predatorCreature.gposx - 1, 0, space.gwspace - 1);
            break;
        case 3: predatorCreature.gposx = gclamp(predatorCreature.gposx + 1, 0, space.ghspace - 1);
            break;

        default:
            break;
    }
}

void RenderCreature::eatPlayer(CreatureCoord& crtr, CreatureCoord& predator)
{
    if(crtr.gposx == predator.gposx && crtr.gposy == predator.gposy)
    {
        crtr.genergy -= 10;
    }
}