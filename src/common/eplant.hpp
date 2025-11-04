#ifndef ENABLEPLANTSINC
#define ENABLEPLANTSINC

#include "plants.hpp"
#include "core/erand.h"

class SafePlant : public Plants
{
    public:
        void spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc) override;
        void consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce) override;
};

class PoisonousPlant : public Plants
{
    public:
        void spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc) override;
        void consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce) override;
};

#endif