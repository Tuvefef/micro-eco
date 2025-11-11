#include "../common/safemush.hpp"

SafeMushroom::SafeMushroom(sCreatureCoord &sccref, sPlantsCoord &spcref, sCreatureEnergy &sceref, MushroomCoord &mref) :
    scc(sccref), spc(spcref), sce(sceref), m(mref)
{}

void SafeMushroom::spawnMush()
{
    do
    {
        m.msx = grmod(WIDTH);
        m.msy = grmod(HEIGHT);
    } while(
        (m.msx == scc.plx && m.msy == scc.ply)   ||
        (m.msx == scc.pyx0 && m.msy == scc.pyy0) ||
        (m.msx == scc.prx0 && m.msy == scc.pry0) ||
        (m.msx == spc.psx && m.msy == spc.psy)   ||
        (m.msx == spc.ppx && m.msy == spc.ppy)
    );
}

void SafeMushroom::consumeMush()
{
    if(scc.plx == m.msx && scc.ply == m.msy)
    {
        sce.generg += 8;
        spawnMush();
    }
}