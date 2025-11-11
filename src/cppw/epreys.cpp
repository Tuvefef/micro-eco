#include "../common/epreys.hpp"
#include "../common/eplant.hpp"

PreyRender0::PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref) : 
    spc(spcref), scc(sccref), sce(sceref), stimer(0), isChasing(false), chaseTimer(0)
{}

void PreyRender0::creatureMove(incvar inc)
{
    if (isChasing)
    {
        chaseTimer++;
        if (chaseTimer >= 10)
        {
            isChasing = false;
            chaseTimer = 0;
        }
    } else {
        if (++stimer > (15 + grmod(10))) 
        { 
            stimer = 0; 
            if (grmod(100) < 16) 
            {
                isChasing = true; 
                chaseTimer = 0;
            }
        }
    }
    
    if(!(isChasing))
    {
        if(std::holds_alternative<int>(inc))
        {
            int coord = std::get<int>(inc);
            switch (coord)
            {
                case 0: scc.pyy0--;
                    break;
                case 1: scc.pyy0++;
                    break;
                case 2: scc.pyx0--;
                    break;
                case 3: scc.pyx0++;
                    break;
        
                default:
                    break;
            }
        }
    } else {
        if     (scc.pyx0 < spc.psx) scc.pyx0++;
        else if(scc.pyx0 > spc.psx) scc.pyx0--;

        if     (scc.pyy0 < spc.psy) scc.pyy0++;
        else if(scc.pyy0 > spc.psy) scc.pyy0--;
    }

    scc.pyx0 = maxn(0, minn(WIDTH - 1, scc.pyx0));
    scc.pyy0 = maxn(0, minn(HEIGHT - 1, scc.pyy0));
}

void PreyRender0::creatureSpawn()
{
    do
    {
        scc.pyx0 = grmod(WIDTH);
        scc.pyy0 = grmod(HEIGHT);
    } while(scc.pyx0 == scc.plx && scc.pyy0 == scc.ply);
}

void PreyRender0::eatPlant()
{
    SafePlant splant(scc, sce, spc);
    if(scc.pyx0 == spc.psx && scc.pyy0 == spc.psy)
    {
        splant.spawnPlants();
    }
}