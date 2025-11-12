#include "../common/toxicmush.hpp"

ToxicMushroom::ToxicMushroom(sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, std::vector<RocksCoord> &rref) :
    scc(sccref), sce(sceref), m(mref), grock(rref)
{}

void ToxicMushroom::spawnMush()
{
    do
    {
        m.mtx = grmod(WIDTH);
        m.mty = grmod(HEIGHT);
    } while(
        std::any_of(grock.begin(), grock.end(), [&](RocksCoord r){ return r.rx == m.mtx && r.ry == m.mty;}) ||  
        (m.mtx == scc.plx && m.mty == scc.ply)   ||
        (m.mtx == scc.pyx0 && m.mty == scc.pyy0) ||
        (m.mtx == scc.prx0 && m.mty == scc.pry0) 
    );
    
}

void ToxicMushroom::consumeMush()
{
    if(scc.plx == m.mtx && scc.ply == m.mty)
    {
        sce.generg -= 8;
        spawnMush();
    }
}