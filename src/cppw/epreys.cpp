#include "../common/epreys.hpp"
#include "../common/safemush.hpp"
#include "../common/eplant.hpp"

PreyRender0::PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref) : 
    spc(spcref), scc(sccref), sce(sceref), m(mref), stimer(0), isChasing(false), chaseTimer(0)
{}

void PreyRender0::creatureMove(incvar inc)
{
    float gdx1 = scc.pyx0 - spc.psx;
    float gdy1 = scc.pyy0 - spc.psy;
    float gdx2 = scc.pyx0 - m.msx;
    float gdy2 = scc.pyy0 - m.msy;

    float gcoord1 = gpowx2(gdx1) + gpowx2(gdy1);
    float gcoord2 = gpowx2(gdx2) + gpowx2(gdy2);

    float gtargx = (gcoord1 < gcoord2) ? spc.psx : m.msx;
    float gtargy = (gcoord1 < gcoord2) ? spc.psy : m.msy;

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
        if     (scc.pyx0 < gtargx) scc.pyx0++;
        else if(scc.pyx0 > gtargx) scc.pyx0--;

        if     (scc.pyy0 < gtargy) scc.pyy0++;
        else if(scc.pyy0 > gtargy) scc.pyy0--;
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

void PreyRender0::eat()
{
    SafePlant splant(scc, sce, spc);
    SafeMushroom sm(scc, spc, sce, m);
    if(
        (scc.pyx0 == spc.psx && scc.pyy0 == spc.psy) ||
        (scc.pyx0 == m.msx && scc.pyy0 == m.msy)
    )
    {
        splant.spawnPlants();
        sm.spawnMush();
    }
}