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
        std::vector<RocksCoord> &grock;
        
        int stimer;
        bool isChasing;
        int chaseTimer;
    public:
        void creatureMove(incvar inc) override;
        void creatureSpawn() override;
        void eat();
        PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref);
};

class PreyRender1 : public CreatureMove, public SpawnCreature
{
    private:
        sPlantsCoord &spc;
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        MushroomCoord &m;
        std::vector<RocksCoord> &grock;

        int stimer;
        int chaseTimer;
        bool isChasing;

    public:
        void creatureMove(incvar inc) override;
        void creatureSpawn() override;
        void eat();
        PreyRender1(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref);
};

#endif