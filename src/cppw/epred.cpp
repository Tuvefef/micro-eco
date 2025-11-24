#include "../common/epred.hpp"
#include "../common/epreys.hpp"

PredatorRender0::PredatorRender0(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref, std::vector<RocksCoord> &rref) :
    stimer(0), isChasing(false), chaseTimer(0), scc(sccref), sce(sceref), spc(spcref), m(mref), grock(rref)
{}

void PredatorRender0::creatureMove(incvar inc)
{
    float dx1 = scc.plx - scc.prx0;
    float dy1 = scc.ply - scc.pry0;
    float dx2 = scc.pyx0 - scc.prx0;
    float dy2 = scc.pyy0 - scc.pry0;
    float dx3 = scc.pyx1 - scc.prx0;
    float dy3 = scc.pyy1 - scc.pry0; 

    float gcoord1 = gpowx2(dx1) + gpowx2(dy1);
    float gcoord2 = gpowx2(dx2) + gpowx2(dy2);
    float gcoord3 = gpowx2(dx3) + gpowx2(dy3);

    float minCoord = gcoord1;
    int targIndex  = 1;

    if(gcoord2 < minCoord)
    {
        minCoord = gcoord2;
        targIndex = 2;
    }

    if(gcoord3 < minCoord)
    {
        minCoord = gcoord3;
        targIndex = 3;
    }

    float gtargx;
    float gtargy;

    switch(targIndex)
    {
        case 1:
            gtargx = scc.plx;
            gtargy = scc.ply;
            break;
        case 2:
            gtargx = scc.pyx0;
            gtargy = scc.pyy0;
            break;
        case 3:
            gtargx = scc.pyx1;
            gtargy = scc.pyy1;
            break;
    }

    int newX = scc.prx0;
    int newY = scc.pry0;

    if(isChasing)
    {
        chaseTimer++;
        if(chaseTimer >= 10)
        {
            isChasing = false;
            chaseTimer = 0;
        }
    } 
    else 
    {
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
                case 0: newY--; break; 
                case 1: newY++; break; 
                case 2: newX--; break; 
                case 3: newX++; break; 
            }
        }
    } 
    else 
    {
        if      (newX < gtargx) newX++;
        else if (newX > gtargx) newX--;

        if      (newY < gtargy) newY++;
        else if (newY > gtargy) newY--;
    }

    newX = maxn(0, minn(WIDTH - 1, newX));
    newY = maxn(0, minn(HEIGHT - 1, newY));

    if(!ROCKMAP[newX][newY])
    {
        scc.prx0 = newX;
        scc.pry0 = newY;
    }
}


void PredatorRender0::creatureEat()
{
    PreyRender0 prey0(spc, scc, sce, m, grock);
    PreyRender1 prey1(spc, scc, sce, m, grock);
    if((scc.prx0 == scc.pyx0 && scc.pry0 == scc.pyy0) ||
       (scc.prx0 == scc.pyx1 && scc.pry0 == scc.pyy1) ||
       (scc.prx0 == scc.plx  && scc.pry0 == scc.ply))
    {
        sce.generg -= 10;
        prey0.creatureSpawn();
        prey1.creatureSpawn();
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