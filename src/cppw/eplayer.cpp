#include "../common/eplayer.hpp"

PlayerRender::PlayerRender(sCreatureCoord &sccref, sCreatureEnergy &sceref, sPlantsCoord &spcref, MushroomCoord &mref, std::vector<RocksCoord> &rref) :
    scc(sccref), sce(sceref), spc(spcref), m(mref), grock(rref)
{}

void PlayerRender::creatureMove(incvar inc)
{
    if(!std::holds_alternative<char>(inc)) return;

    char coord = std::get<char>(inc);
    int newX = scc.plx;
    int newY = scc.ply;

    switch(coord)
    {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        case 'q': sce.generg = 0; return;
    }

    newX = maxn(0, minn(WIDTH - 1, newX));
    newY = maxn(0, minn(HEIGHT - 1, newY));

    if(!ROCKMAP[newX][newY])
    {
        scc.plx = newX;
        scc.ply = newY;
    }
}

void PlayerRender::creatureEat()
{
    PreyRender0 rprey0(spc, scc, sce, m, grock);
    PreyRender1 rprey1(spc, scc, sce, m, grock);
    if((scc.plx == scc.pyx0 && scc.ply == scc.pyy0) || (scc.plx == scc.pyx1 && scc.ply == scc.pyy1))
    {
        sce.generg += 18;
        rprey0.creatureSpawn();
        rprey1.creatureSpawn();
    }
}

int PlayerRender::playerLowEnerg() const
{
    return --sce.generg;
}

int PlayerRender::playerDead() const
{
    return sce.generg <= 0;
}