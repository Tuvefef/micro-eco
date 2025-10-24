#ifndef MOOSHROOMH
#define MOOSHROOMH

#include <cstdlib>
#include "structs.h"

class Mooshroom
{
    public:
        virtual void spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space) = 0;
        virtual void eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space) = 0;
        virtual ~Mooshroom() = default;
        
};

#endif