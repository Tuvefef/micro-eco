#ifndef POISONOUSMOOSH
#define POISONOUSMOOSH

#include "mooshroom.h"

class PoisonousMoosh : public Mooshroom
{
    public:
        void spawnMoosh(MooshroomCoord& moosh0, CreatureCoord& crtr, SpaceCoords& space) override;
        void eatMoosh(CreatureCoord& crtr, MooshroomCoord& moosh0, SpaceCoords& space, Hallucinogen& gall, EnergCreature& energy) override;
};

#endif