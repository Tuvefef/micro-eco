#ifndef PREYLOGIC
#define PREYLOGIC

#include "creatures.hpp"

class PreyRender0 : public CreatureMove, public SpawnCreature
{
    public:
        void creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc) override;
        void creatureSpawn(sCreatureCoord &scc) override;
};

#endif