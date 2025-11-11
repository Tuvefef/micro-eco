#include "../common/epred.hpp"
#include "../common/epreys.hpp"

PredatorRender0::PredatorRender0(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref) :
    stimer(0), isChasing(false), chaseTimer(0), scc(sccref), sce(sceref), spc(spcref), m(mref)
{}

void PredatorRender0::creatureMove(incvar inc)
{
    float dx1 = scc.plx - scc.prx0;
    float dy1 = scc.ply - scc.pry0;
    float dx2 = scc.pyx0 - scc.prx0;
    float dy2 = scc.pyy0 - scc.pry0;

    float gcoord1 = gpowx2(dx1) + gpowx2(dy1);
    float gcoord2 = gpowx2(dx2) + gpowx2(dy2);

    float gtargx = (gcoord1 < gcoord2) ? scc.plx : scc.pyx0;
    float gtargy = (gcoord1 < gcoord2) ? scc.ply : scc.pyy0;

    if(isChasing)
    {
        chaseTimer++;
        if(chaseTimer >= 10)
        {
            isChasing = false;
            chaseTimer = 0;
        }
    } else {
        if(++stimer > (15 + grmod(10))) 
        { 
            stimer = 0; 
            if(grmod(100) < 16) 
            {
                isChasing = true; 
                chaseTimer = 0;
            }
        }
    }

    if(!isChasing)
    {
        if(std::holds_alternative<int>(inc))
        {
            int coord = std::get<int>(inc);
            switch (coord)
            {
                case 0: scc.pry0--;
                    break;
                case 1: scc.pry0++;
                    break;
                case 2: scc.prx0--;
                    break;
                case 3: scc.prx0++;
                    break;
        
                default:
                    break;
            }
        }
    } else {
        if      (scc.prx0 < gtargx) scc.prx0++;
        else if (scc.prx0 > gtargx) scc.prx0--;

        if      (scc.pry0 < gtargy) scc.pry0++;
        else if (scc.pry0 > gtargy) scc.pry0--;
    }

    scc.prx0 = maxn(0, minn(WIDTH - 1, scc.prx0));
    scc.pry0 = maxn(0, minn(HEIGHT - 1, scc.pry0));
}

void PredatorRender0::creatureEat()
{
    PreyRender0 prey0(spc, scc, sce, m);
    if((scc.prx0 == scc.plx && scc.pry0 == scc.ply) || 
    (scc.prx0 == scc.pyx0 && scc.pry0 == scc.pyy0))
    {
        sce.generg -= 5;
        prey0.creatureSpawn();
    } 
}

void PredatorRender0::creatureSpawn()
{
    do
    {
        scc.prx0 = grmod(WIDTH);
        scc.pry0 = grmod(HEIGHT);
    } while (scc.prx0 == scc.plx && scc.pry0 == scc.ply);
    
}