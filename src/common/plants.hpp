#ifndef PLANTSH
#define PLANTSH

#include <cstdlib>

#include "utils.hpp"
#include "structs.hpp"

class Plants
{
    public:
        virtual void spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc) = 0;
        virtual void consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce)= 0;
        virtual ~Plants() = default;
};

#endif