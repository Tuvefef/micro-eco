#ifndef HALLUCINOGENMUSHLOGICH
#define HALLUCINOGENMUSHLOGICH

#include "mushroom.hpp"

class HallucinogenMushroom : public Mushroom
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        sPlantsCoord &spc;
        MushroomCoord &m;
        Hallucinogen &h;
    public:
        void spawnMush() override;
        void consumeMush() override;
        void effectMush();
        int low();
        int ticks();
        HallucinogenMushroom(sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, sPlantsCoord &spcref, Hallucinogen &href);
};

#endif