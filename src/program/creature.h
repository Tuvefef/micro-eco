#ifndef CREATURE
#define CREATURE

#include <cstdlib>
#include "structs.h"
#include "sysmath.h"

class RenderCreature
{
    public:
        void renderPlayermove(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space, char ginp);
        void creaturealowenerg(CreatureCoord& crtr);
        bool creatureDead(CreatureCoord& crtr);
        void preyCreature(CreatureCoord& npc, SpaceCoords& space);
        void spawnPrey(CreatureCoord& npc, CreatureCoord& crtr, SpaceCoords& space);
        void eatPrey(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space);

        void predatorCreature(CreatureCoord& predator, SpaceCoords& space);
        void eatPlayer(CreatureCoord& crtr, CreatureCoord& predator);
};

#endif