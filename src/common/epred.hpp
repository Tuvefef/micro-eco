#ifndef PREDATORLOGICH
#define PREDATORLOGICH

#include "creatures.hpp"

class PredatorRender0 : public CreatureMove, public CreatureEat, public SpawnCreature
{
    public:
        void creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc) override;
        void creatureEat(sCreatureCoord &scc, sCreatureEnergy *sce) override;
        void creatureSpawn(sCreatureCoord &scc) override;
};

#endif