#ifndef PLANTSH
#define PLANTSH

#include <cstdlib>
#include "structs.h"

class Plant
{
    public:
        void spawnPlant(CreatureCoord& crtr, PlantCoord& plant0);
        void spawnPoisonousPlant(CreatureCoord& crtr, PlantCoord& plant0, PoisonousPlantCoord& pplant);
};

#endif