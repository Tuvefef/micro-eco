#include "hmoosh.h"

void HallucinogenMoosh::spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space)
{
    do
    {
        moosh0.ghpx = rand() % space.gwspace;
        moosh0.ghpy = rand() % space.ghspace;
    } while(moosh0.ghpx == crtr.gposx && moosh0.ghpy == crtr.gposy);
}

void HallucinogenMoosh::effectMoosh(CreatureCoord& crtr, Hallucinogen& gall)
{
    if(!gall.ishallucination || gall.hallucinationTicks <= 0)
        return;

    int ginitx = crtr.gposx + 0;
    int ginity = crtr.gposy + 0;

    double e = (double)rand() / RAND_MAX;
    if(e < HALLUCINOGENPROB)
    {
        int gedx = (rand() % (2 * 1 + 1)) - 1;
        int gedy = (rand() % (2 * 1 + 1)) - 1;

        ginitx += gedx;
        ginity+= gedy;
    }

    crtr.gposx = ginitx;
    crtr.gposy = ginity;
}

void HallucinogenMoosh::eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space, Hallucinogen& gall)
{
    if(crtr.gposx == moosh0.ghpx && crtr.gposy == moosh0.ghpy)
    {
        crtr.genergy += 7;

        gall.ishallucination = true;
        gall.hallucinationTicks = MAXHALLUCINOGEN;
        spawnMoosh(moosh0, crtr, space);
    }
}

int HallucinogenMoosh::lowEffect(Hallucinogen& gall)
{
    return gall.hallucinationTicks--;
}

bool HallucinogenMoosh::tickteffect(Hallucinogen& gall)
{
    return gall.hallucinationTicks <= ENDENTITY;
}