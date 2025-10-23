#ifndef CREATURE
#define CREATURE

#include "plants.h"
#include "structs.h"
#include "sysmath.h"

class RenderCreature
{
    public:
        void renderPlayermove(CreatureCoord& crtr, Plant& plant0, PlantCoord& plant, PoisonousPlantCoord& pplant, char ginp);
        void creaturealowenerg(CreatureCoord& crtr);
        bool creatureDead(CreatureCoord& crtr);
        void preyCreature(CreatureCoord& npc);
        void creatureEatPlant(CreatureCoord& crtr, Plant& plant0, PlantCoord& plant, PoisonousPlantCoord& pplant);
        void spawnPrey(CreatureCoord& npc, CreatureCoord& crtr);
        void eatPrey(CreatureCoord& crtr, CreatureCoord& npc);

        void predatorCreature(CreatureCoord& predator);
        void eatPlayer(CreatureCoord& crtr, CreatureCoord& predator);
};

#endif