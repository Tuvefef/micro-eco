#ifndef PLAYERLOGIC
#define PLAYERLOGIC

#include "creatures.hpp"
#include "epreys.hpp"

class PlayerRender : public CreatureMove, public CreatureEat
{
    public:
        void creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc) override;
        void creatureEat(sCreatureCoord &scc, sCreatureEnergy *sce) override;

        int playerLowEnerg(sCreatureEnergy &sce) const;
        int playerDead(const sCreatureEnergy &sce) const;
};

#endif