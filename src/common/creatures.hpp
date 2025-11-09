#ifndef CREATURESH
#define CREATURESH

#include <cstdlib>

#include "core/utils.hpp"
#include "core/structs.hpp"
#include "core/grand.h"

class CreatureMove
{
    public:
        virtual void creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc) = 0;
        virtual ~CreatureMove() = default;
};

class SpawnCreature
{
    public:
        virtual void creatureSpawn(sCreatureCoord &scc) = 0;
        virtual ~SpawnCreature() = default;
};

class CreatureEat 
{
    public:
        virtual void creatureEat(sCreatureCoord &scc, sCreatureEnergy *sce) = 0;
        virtual ~CreatureEat() = default;
};

#endif