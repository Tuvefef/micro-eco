#ifndef PREDATORLOGICH
#define PREDATORLOGICH

#include "creatures.hpp"

class PredatorRender0 : public CreatureMove, public CreatureEat, public SpawnCreature
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        sPlantsCoord &spc;
        MushroomCoord &m;
        std::vector<RocksCoord> &grock;
        int stimer;
        bool isChasing;
        int chaseTimer;
    public:
        void creatureMove(incvar inc) override;
        void creatureEat() override;
        void creatureSpawn() override;
        PredatorRender0(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref, std::vector<RocksCoord> &rref);
};

#endif