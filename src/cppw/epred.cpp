#include "../common/epred.hpp"
#include "../common/epreys.hpp"

void PredatorRender0::creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc)
{
    float dx1 = scc.plx - scc.prx0;
    float dy1 = scc.ply - scc.pry0;
    float dx2 = scc.pyx0 - scc.prx0;
    float dy2 = scc.pyy0 - scc.pry0;

    float gcoord1 = gpowx2(dx1) + gpowx2(dy1);
    float gcoord2 = gpowx2(dx2) + gpowx2(dy2);

    float gtargx = (gcoord1 < gcoord2) ? scc.plx : scc.pyx0;
    float gtargy = (gcoord1 < gcoord2) ? scc.ply : scc.pyy0;

    if      (scc.prx0 < gtargx) scc.prx0++;
    else if (scc.prx0 > gtargx) scc.prx0--;

    if      (scc.pry0 < gtargy) scc.pry0++;
    else if (scc.pry0 > gtargy) scc.pry0--;

    scc.prx0 = maxn(0, minn(WIDTH - 1, scc.prx0));
    scc.pry0 = maxn(0, minn(HEIGHT - 1, scc.pry0));
}

void PredatorRender0::creatureEat(sCreatureCoord &scc, sCreatureEnergy *sce)
{
    PreyRender0 prey0;
    if((scc.prx0 == scc.plx && scc.pry0 == scc.ply) || 
    (scc.prx0 == scc.pyx0 && scc.pry0 == scc.pyy0))
    {
        sce->generg -= 20;
        prey0.creatureSpawn(scc);
    } 
}

void PredatorRender0::creatureSpawn(sCreatureCoord &scc)
{
    do
    {
        scc.prx0 = rand() % WIDTH;
        scc.pry0 = rand() % HEIGHT;
    } while (scc.prx0 == scc.plx && scc.pry0 == scc.ply);
    
}