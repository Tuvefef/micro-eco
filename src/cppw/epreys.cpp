#include "../common/epreys.hpp"

void PreyRender0::creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc)
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

        scc.pyx0 = maxn(0, minn(WIDTH - 1, scc.pyx0));
        scc.pyy0 = maxn(0, minn(HEIGHT - 1, scc.pyy0));
    }
}

void PreyRender0::creatureSpawn(sCreatureCoord &scc)
{
    do
    {
        scc.pyx0 = grmod(WIDTH);
        scc.pyy0 = grmod(HEIGHT);
    } while(scc.pyx0 == scc.plx && scc.pyy0 == scc.ply);
}