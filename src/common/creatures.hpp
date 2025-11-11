#ifndef CREATURESH
#define CREATURESH

#include <cstdlib>

#include "core/utils.hpp"
#include "core/structs.hpp"
#include "core/grand.h"

class CreatureMove
{
    public:
        virtual void creatureMove(incvar inc) = 0;
        virtual ~CreatureMove() = default;
};

class SpawnCreature
{
    public:
        virtual void creatureSpawn() = 0;
        virtual ~SpawnCreature() = default;
};

class CreatureEat 
{
    public:
        virtual void creatureEat() = 0;
        virtual ~CreatureEat() = default;
};

#endif