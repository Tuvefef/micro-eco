#ifndef PLAYERLOGIC
#define PLAYERLOGIC

#include "creatures.hpp"
#include "epreys.hpp"

class PlayerRender : public CreatureMove, public CreatureEat
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        sPlantsCoord &spc;
        MushroomCoord &m;
    public:
        void creatureMove(incvar inc) override;
        void creatureEat() override;

        int playerLowEnerg() const;
        int playerDead() const;
        PlayerRender(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref);
};

#endif