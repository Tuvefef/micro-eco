#ifndef MUSHROOMLOGICH
#define MUSHROOMLOGICH

#include "mushroom.hpp"

class SafeMushroom : public Mushroom
{
    private:
        sCreatureCoord &scc;
        sPlantsCoord &spc;
        sCreatureEnergy &sce;
        MushroomCoord &m;
    public:
        void spawnMush() override;
        void consumeMush() override;
        SafeMushroom(sCreatureCoord &sccref, sPlantsCoord &spcref, sCreatureEnergy &sceref, MushroomCoord &mref);
};

#endif