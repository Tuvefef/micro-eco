#include "../common/eplant.hpp"

SafePlant::SafePlant(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref) :
    scc(sccref), sce(sceref), spc(spcref)
{}

PoisonousPlant::PoisonousPlant(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref) :
    scc(sccref), sce(sceref), spc(spcref)
{}

void SafePlant::spawnPlants()
{
    do
    {
        spc.psx = grmod(WIDTH);
        spc.psy = grmod(HEIGHT);
    } while(spc.psx == scc.plx && spc.psy == scc.ply);

}

void SafePlant::consumePlant()
{
    if(scc.plx == spc.psx && scc.ply == spc.psy)
    {
        sce.generg += 3;
        spawnPlants();
    }
}

void PoisonousPlant::spawnPlants()
{
    do
    {
        spc.ppx = grmod(WIDTH);
        spc.ppy = grmod(HEIGHT);
    } while(spc.ppx == scc.plx && spc.ppy == scc.ply);
    
}

void PoisonousPlant::consumePlant()
{
    if(scc.plx == spc.ppx && scc.ply == spc.ppy)
    {
        sce.generg -= 3;
        spawnPlants();
    }
}