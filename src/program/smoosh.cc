#include "smoosh.h"

void SafeMoosh::spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space)
{
    do
    {
        moosh0.gmfx = rand() % space.gwspace;
        moosh0.gmfy = rand() % space.ghspace;
    } while(moosh0.gmfx == crtr.gposx && moosh0.gmfy == crtr.gposy);
}

void SafeMoosh::eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space, Hallucinogen& gall)
{
    if(crtr.gposx == moosh0.gmfx && crtr.gposy == moosh0.gmfy)
    {
        crtr.genergy += 7;
        spawnMoosh(moosh0, crtr, space);
    }
}