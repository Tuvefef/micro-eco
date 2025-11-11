#ifndef ENABLEPLANTSINC
#define ENABLEPLANTSINC

#include "plants.hpp"

class SafePlant : public Plants
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        sPlantsCoord &spc;
    public:
        void spawnPlants() override;
        void consumePlant() override;
        SafePlant(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref);
};

class PoisonousPlant : public Plants
{
    private:
        sCreatureCoord &scc;
        sCreatureEnergy &sce;
        sPlantsCoord &spc;
    public:
        void spawnPlants() override;
        void consumePlant() override;
        PoisonousPlant(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref);
};

#endif