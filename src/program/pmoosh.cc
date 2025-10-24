#include "pmoosh.h"

void PoisonousMoosh::spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space)
{
    do
    {
        moosh0.gmpx = rand() % space.gwspace;
        moosh0.gmpy = rand() % space.ghspace;
    } while(moosh0.gmpx == crtr.gposx && moosh0.gmpy == crtr.gposy);
}

void PoisonousMoosh::eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space)
{
    if(crtr.gposx == moosh0.gmpx && crtr.gposy == moosh0.gmpy)
    {
        crtr.genergy -= 9;
        spawnMoosh(moosh0, crtr, space);
    }
}