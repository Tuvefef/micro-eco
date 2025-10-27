#ifndef INCPLAYER
#define INCPLAYER

#include "creature.h"

class RenderPlayer : public CreatureMove, CreatureEat
{
    public:
        void moveCreature(CreatureCoord& crtr, SpaceCoords& space, vIntChar inc, EnergCreature& energy) override;
        void creatureEat(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space, EnergCreature& energy) override;
        
        void playerLowenerg(EnergCreature& energy);
        bool playerDead(EnergCreature& energy);
};

#endif