#ifndef INCCREATURE
#define INCCREATURE

#include "creature.h"

class RenderPrey : public CreatureMove, CreatureSpawn
{
    public:
        void moveCreature(CreatureCoord& npc, SpaceCoords& space, vIntChar inc, EnergCreature& energy) override;
        void creatureSpawn(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space) override;
};

class RenderPredator : public CreatureMove, CreatureEat
{
    public:
        void moveCreature(CreatureCoord& predator, SpaceCoords& space, vIntChar inc, EnergCreature& energy) override;
        void creatureEat(CreatureCoord& crtr, CreatureCoord& predator, SpaceCoords& space, EnergCreature& energy) override;
};

#endif