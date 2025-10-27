#ifndef HALLUCINOGENMOOSH
#define HALLUCINOGENMOOSH

#include "mooshroom.h"

class HallucinogenMoosh : public Mooshroom
{
    public:
        void spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space) override;
        void effectMoosh(CreatureCoord& crtr, Hallucinogen& gall);
        void eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space, Hallucinogen& gall, EnergCreature& energy) override;
        int lowEffect(Hallucinogen& gall);
        bool tickteffect(Hallucinogen& gall);
};

#endif