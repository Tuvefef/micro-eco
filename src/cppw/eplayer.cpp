#include "../common/eplayer.hpp"

PlayerRender::PlayerRender(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref) :
    scc(sccref), sce(sceref), spc(spcref), m(mref)
{}

void PlayerRender::creatureMove(incvar inc)
{
    if(std::holds_alternative<char>(inc))
    {
        char coord = std::get<char>(inc);
        switch(coord)
        {
            case 'w': scc.ply--;
                break;
            case 's': scc.ply++;
                break;
            case 'a': scc.plx--;
                break;
            case 'd': scc.plx++;
                break;
            case 'q': sce.generg = 0;
                break;
    
            default:
                break;
        }

        scc.plx = maxn(0, minn(WIDTH - 1, scc.plx));
        scc.ply = maxn(0, minn(HEIGHT - 1, scc.ply));
    }
}

void PlayerRender::creatureEat()
{
    PreyRender0 rprey(spc, scc, sce, m);
    if(scc.plx == scc.pyx0 && scc.ply == scc.pyy0)
    {
        sce.generg += 15;
        rprey.creatureSpawn();
    }
}

int PlayerRender::playerLowEnerg() const
{
    return sce.generg--;
}

int PlayerRender::playerDead() const
{
    return sce.generg <= 0;
}