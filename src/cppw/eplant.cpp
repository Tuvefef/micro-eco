#include "../common/eplant.hpp"

void SafePlant::spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc)
{
    do
    {
        spc.psx = grmod(WIDTH);
        spc.psy = grmod(HEIGHT);
    } while(spc.psx == scc.plx && spc.psy == scc.ply);
    
}

void SafePlant::consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce)
{
    if(scc.plx == spc.psx && scc.ply == spc.psy)
    {
        sce.generg += 3;
        spawnPlants(scc, spc);
    }
}

void PoisonousPlant::spawnPlants(sCreatureCoord &scc, sPlantsCoord &spc)
{
    do
    {
        spc.ppx = grmod(WIDTH);
        spc.ppy = grmod(HEIGHT);
    } while(spc.ppx == scc.plx && spc.ppy == scc.ply);
    
}

void PoisonousPlant::consumePlant(sCreatureCoord &scc, sPlantsCoord &spc, sCreatureEnergy &sce)
{
    if(scc.plx == spc.ppx && scc.ply == spc.ppy)
    {
        sce.generg -= 3;
        spawnPlants(scc, spc);
    }
}