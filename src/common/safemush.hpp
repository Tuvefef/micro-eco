#ifndef MUSHROOMLOGICH
#define MUSHROOMLOGICH

#include "mushroom.hpp"

class SafeMushroom : public Mushroom
{
    private:
        const sCreatureCoord &scc;
        const sPlantsCoord &spc;
        sCreatureEnergy &sce;
        MushroomCoord &m;
    public:
        void spawnMush() override;
        void consumeMush() override;
        SafeMushroom(const sCreatureCoord &sccref, const sPlantsCoord &spcref, sCreatureEnergy &sceref, MushroomCoord &mref);
};

#endif