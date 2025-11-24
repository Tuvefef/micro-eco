#include "../common/epreys.hpp"
#include "../common/safemush.hpp"
#include "../common/toxicmush.hpp"
#include "../common/eplant.hpp"

PreyRender0::PreyRender0(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref) : 
    spc(spcref), scc(sccref), sce(sceref), m(mref), stimer(0), isChasing(false), chaseTimer(0), grock(rref)
{}

PreyRender1::PreyRender1(sPlantsCoord &spcref, sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref) :
    spc(spcref), scc(sccref), sce(sceref), m(mref), stimer(0), isChasing(false), chaseTimer(0), grock(rref)
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

void PreyRender1::creatureMove(incvar inc)
{
    float gdx1 = scc.pyx1 - scc.pyx0;
    float gdy1 = scc.pyy1 - scc.pyy0;
    float gdx2 = scc.pyx1 - m.msx;
    float gdy2 = scc.pyy1 - m.msy;
    float gdx3 = scc.pyx1 - m.mtx;
    float gdy3 = scc.pyy1 - m.mty;

    float gcoord1 = gpowx2(gdx1) + gpowx2(gdy1);
    float gcoord2 = gpowx2(gdx2) + gpowx2(gdy2);
    float gcoord3 = gpowx2(gdx3) + gpowx2(gdy3);

    float minCoord = gcoord1;
    int targIndex  = 1;

    if(gcoord2 < minCoord) {
        minCoord = gcoord2;
        targIndex = 2;
    }

    if(gcoord3 < minCoord) {
        minCoord = gcoord3;
        targIndex = 3;
    }

    float gtargx;
    float gtargy;

    switch(targIndex)
    {
        case 1:
            gtargx = scc.pyx0;
            gtargy = scc.pyy0;
            break;

        case 2:
            gtargx = m.msx;
            gtargy = m.msy;
            break;

        case 3:
            gtargx = m.mtx;
            gtargy = m.mty;
            break;
    }

    int gnewx = scc.pyx1;
    int gnewy = scc.pyy1;

    if (isChasing)
    {
        chaseTimer++;
        if (chaseTimer >= 10)
        {
            isChasing = false;
            chaseTimer = 0;
        }
    } 
    else 
    {
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

    if (!isChasing)
    {
        if (std::holds_alternative<int>(inc))
        {
            int coord = std::get<int>(inc);
            switch (coord)
            {
                case 0: gnewy--; break;
                case 1: gnewy++; break;
                case 2: gnewx--; break;
                case 3: gnewx++; break;
                default: break;
            }
        }
    } 
    else 
    {
        if     (gnewx < gtargx) gnewx++;
        else if(gnewx > gtargx) gnewx--;

        if     (gnewy < gtargy) gnewy++;
        else if(gnewy > gtargy) gnewy--;
    }

    if(!ROCKMAP[gnewx][gnewy])
    {
        scc.pyx1 = maxn(0, minn(WIDTH  - 1, gnewx));
        scc.pyy1 = maxn(0, minn(HEIGHT - 1, gnewy));
    }
}

void PreyRender0::creatureSpawn()
{
    do
    {
        scc.pyx0 = grmod(WIDTH);
        scc.pyy0 = grmod(HEIGHT);
    } while(scc.pyx0 == scc.plx && scc.pyy0 == scc.ply);
}

void PreyRender1::creatureSpawn()
{
    do
    {
        scc.pyx1 = grmod(WIDTH);
        scc.pyy1 = grmod(HEIGHT);
    } while(scc.plx == scc.pyx1 && scc.ply == scc.pyy1);
    
}

void PreyRender0::eat()
{
    SafePlant splant(scc, sce, spc);
    SafeMushroom sm(scc, spc, sce, m, grock);
    if(
        (scc.pyx0 == spc.psx && scc.pyy0 == spc.psy) ||
        (scc.pyx0 == m.msx && scc.pyy0 == m.msy)
    )
    {
        splant.spawnPlants();
        sm.spawnMush();
    }
}

void PreyRender1::eat()
{
    PreyRender0 prey0(spc, scc, sce, m, grock);
    SafeMushroom sm(scc, spc, sce, m, grock);
    ToxicMushroom tm(scc, sce, m, grock);

    if(
        (scc.pyx1 == scc.pyx0 && scc.pyy1 == scc.pyy0) ||
        (scc.pyx1 == m.msx && scc.pyy1 == m.msy)       ||
        (scc.pyx1 == m.mtx && scc.pyy1 == m.mty)
    )
    {
        prey0.creatureSpawn();
        sm.spawnMush();
        tm.spawnMush();
    }
}