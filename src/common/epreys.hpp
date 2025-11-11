#ifndef PREYLOGIC
#define PREYLOGIC

#include "creatures.hpp"

class PreyRender0 : public CreatureMove, public SpawnCreature
{
    private:
        sPlantsCoord &spc;
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        int stimer;
        bool isChasing;
        int chaseTimer;
    public:
        void creatureMove(incvar inc) override;
        void creatureSpawn() override;
        void eatPlant();
        PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref);
};

#endif