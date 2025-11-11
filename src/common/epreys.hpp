#ifndef PREYLOGIC
#define PREYLOGIC

#include "creatures.hpp"

class PreyRender0 : public CreatureMove, public SpawnCreature
{
    private:
        sPlantsCoord &spc;
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        MushroomCoord &m;
        int stimer;
        bool isChasing;
        int chaseTimer;
    public:
        void creatureMove(incvar inc) override;
        void creatureSpawn() override;
        void eat();
        PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref);
};

#endif