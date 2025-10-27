#ifndef PLANTSH
#define PLANTSH

#include <cstdlib>
#include "structs.h"

class Plants
{
    public:
        virtual void spawnPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space) = 0;
        virtual void eatPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space, EnergCreature& energy) = 0;
        virtual ~Plants() = default;
};

#endif