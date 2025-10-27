#ifndef PPLANTS
#define PPLANTS

#include "plants.h"

class PoisonousPlant : public Plants
{
    public:
        void spawnPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space) override;
        void eatPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space, EnergCreature& energy) override;
};

#endif