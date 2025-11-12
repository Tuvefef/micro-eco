#include "../common/hallmush.hpp"

HallucinogenMushroom::HallucinogenMushroom(sCreatureCoord &sccref, sCreatureEnergy &sceref, MushroomCoord &mref, sPlantsCoord &spcref, Hallucinogen &href) :
    scc(sccref), sce(sceref), m(mref), spc(spcref), h(href)
{}

void HallucinogenMushroom::spawnMush()
{
    do
    {
        m.mhx = grmod(WIDTH);
        m.mhy = grmod(HEIGHT);
    } while (
        (m.mhx == scc.plx && m.mhy == scc.ply)   ||
        (m.mhx == scc.pyx0 && m.mhy == scc.pyy0) ||
        (m.mhx == scc.prx0 && m.mhy == scc.pry0) ||
        (m.mhx == spc.psx && m.mhy == spc.psy)   ||
        (m.mhx == spc.ppx && m.mhy == spc.ppy)
    );
    
}

void HallucinogenMushroom::consumeMush()
{
    if(scc.plx == m.mhx && scc.ply == m.mhy)
    {
        sce.generg += 10;
        h.isHallucination = true;
        h.hticks = 10;
        spawnMush();
    }
}

void HallucinogenMushroom::effectMush()
{
    if(!h.isHallucination || h.hticks <= 0)
        return;

    int gedx = (grand() % 3) - 1; 
    int gedy = (grand() % 3) - 1;

    double e = (double)grand() / (double)LIMG;
    if(e < 0.59)
    {
        scc.plx += gedx;
        scc.ply += gedy;
    }
}

int HallucinogenMushroom::low()
{
    return h.hticks--;
}

int HallucinogenMushroom::ticks()
{
    return h.hticks <= 0;
}