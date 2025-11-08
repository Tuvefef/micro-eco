#ifndef PREYLOGIC
#define PREYLOGIC

#include "creatures.hpp"

class PreyRender0 : public CreatureMove, public SpawnCreature
{
    private:
        const sPlantsCoord *spctrg;
        int stimer;
        bool isChasing;
        int chaseTimer;
    public:
        void creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc) override;
        void creatureSpawn(sCreatureCoord &scc) override;
        void eatPlant(sPlantsCoord &spc, sCreatureCoord &scc);
        PreyRender0(const sPlantsCoord *targ);
};

#endif