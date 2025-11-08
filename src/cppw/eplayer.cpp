#include "../common/eplayer.hpp"

void PlayerRender::creatureMove(sCreatureCoord &scc, sCreatureEnergy *sce, incvar inc)
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
            case 'q': if(sce)sce->generg = 0;
                break;
    
            default:
                break;
        }

        scc.plx = maxn(0, minn(WIDTH - 1, scc.plx));
        scc.ply = maxn(0, minn(HEIGHT - 1, scc.ply));
    }
}

void PlayerRender::creatureEat(sCreatureCoord &scc, sCreatureEnergy *sce)
{
    PreyRender0 rprey(nullptr);
    if(scc.plx == scc.pyx0 && scc.ply == scc.pyy0)
    {
        sce->generg += 8;
        rprey.creatureSpawn(scc);
    }
}

int PlayerRender::playerLowEnerg(sCreatureEnergy &sce) const
{
    return sce.generg--;
}

int PlayerRender::playerDead(const sCreatureEnergy &sce) const
{
    return sce.generg <= 0;
}