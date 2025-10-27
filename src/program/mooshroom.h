#ifndef MOOSHROOMH
#define MOOSHROOMH

#include <cstdlib>
#include "sysmath.h"
#include "structs.h"

class Mooshroom
{
    public:
        virtual void spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space) = 0;
        virtual void eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space, Hallucinogen& gall, EnergCreature& energy) = 0;
        virtual ~Mooshroom() = default;
        
};

#endif