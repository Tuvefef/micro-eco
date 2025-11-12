#ifndef TOXICMUSHLOGICH
#define TOXICMUSHLOGICH

#include "mushroom.hpp"

class ToxicMushroom : public Mushroom
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        MushroomCoord &m;
        std::vector<RocksCoord> &grock;
    public:
        void spawnMush() override;
        void consumeMush() override;
        ToxicMushroom(sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref);
};

#endif