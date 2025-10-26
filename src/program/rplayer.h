#ifndef INCPLAYER
#define INCPLAYER

#include "creature.h"

class RenderPlayer : public CreatureMove, CreatureEat
{
    public:
        void moveCreature(CreatureCoord& crtr, SpaceCoords& space, vIntChar inc) override;
        void creatureEat(CreatureCoord& crtr, CreatureCoord& npc, SpaceCoords& space) override;
        
        void playerLowenerg(CreatureCoord& crtr);
        bool playerDead(CreatureCoord& crtr);
};

#endif