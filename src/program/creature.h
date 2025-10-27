#ifndef CREATUREH
#define CREATUREH

#include <cstdlib>
#include <variant>

#include "structs.h"
#include "sysmath.h"

using vIntChar = std::variant<int, char>;

class CreatureMove
{
    public:
        virtual void moveCreature(CreatureCoord& crtr, SpaceCoords& space, vIntChar inc, EnergCreature& energy) = 0;
        virtual ~CreatureMove() = default;
};

class CreatureSpawn
{
    public:
        virtual void creatureSpawn(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space) = 0;
        virtual ~CreatureSpawn() = default;
};

class CreatureEat
{
    public:
        virtual void creatureEat(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space, EnergCreature& energy) = 0;
        virtual ~CreatureEat() = default;
};

class CreatureEnergy
{
    public:
        virtual int lowEnerg(CreatureEnergy& energy) = 0;
        virtual ~CreatureEnergy() = default;
};

class CreatureDead
{
    public:
        virtual bool creatureDead(CreatureEnergy& energy) = 0;
        virtual ~CreatureDead() = default;
};

#endif