#ifndef EPLANTSH
#define EPLANTSH

#include "plants.h"

class EdiblePlant : public Plants
{
    public:
        void spawnPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space) override;
        void eatPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space, EnergCreature& energy) override;
};

#endif