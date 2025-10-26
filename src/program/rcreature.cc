#include "rcreature.h"

void RenderPrey::moveCreature(CreatureCoord& npc, SpaceCoords& space, vIntChar inc)
{
    if(std::holds_alternative<int>(inc))
    {
        int ginp = std::get<int>(inc);
        switch (ginp)
        {
            case IncCoords::iccoorw: npc.gposy = gclamp(npc.gposy - 1, 0, space.gwspace - 1);
                break;
            case IncCoords::iccoors: npc.gposy = gclamp(npc.gposy + 1, 0, space.ghspace - 1);
                break;
            case IncCoords::iccoora: npc.gposx = gclamp(npc.gposx - 1, 0, space.gwspace - 1);
                break;
            case IncCoords::iccoord: npc.gposx = gclamp(npc.gposx + 1, 0, space.ghspace - 1);
                break;
    
            default:
                break;
        }
    }
}

void RenderPredator::moveCreature(CreatureCoord& predator, SpaceCoords& space, vIntChar inc)
{
    if(std::holds_alternative<int>(inc))
    {
        int ginp = std::get<int>(inc);
        switch(ginp)
        {
            case IncCoords::iccoorw: predator.gposy = gclamp(predator.gposy - 1, 0, space.gwspace -1);
                break;
            case IncCoords::iccoors: predator.gposy = gclamp(predator.gposy + 1, 0, space.ghspace - 1);
                break;
            case IncCoords::iccoora: predator.gposx = gclamp(predator.gposx - 1, 0, space.gwspace - 1);
                break;
            case IncCoords::iccoord: predator.gposx = gclamp(predator.gposx + 1, 0, space.ghspace - 1);
                break;

            default:
                break;
        }
    }
}

void RenderPrey::creatureSpawn(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space)
{
    do
    {
        npc.gposx = rand() % space.gwspace;
        npc.gposy = rand() % space.ghspace;
    } while (npc.gposx == crtr.gposx && npc.gposy == crtr.gposy);
}

void RenderPredator::creatureEat(CreatureCoord& crtr, CreatureCoord& predator, SpaceCoords& space)
{
    if(crtr.gposx == predator.gposx && crtr.gposy == predator.gposy)
    {
        crtr.genergy -= 20;
    }
}