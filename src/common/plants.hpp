#ifndef PLANTSH
#define PLANTSH

#include <cstdlib>

#include "core/utils.hpp"
#include "core/structs.hpp"
#include "core/grand.h"

class Plants
{
    public:
        virtual void spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc) = 0;
        virtual void consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce)= 0;
        virtual ~Plants() = default;
};

#endif