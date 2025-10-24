#ifndef ENTITYSTRUCTS
#define ENTITYSTRUCTS

struct CreatureCoord
{
    int gposx;
    int gposy;
    int genergy;
};

struct PlantCoord
{
    int gpx;
    int gpy;

                    /* poisonous plant part */

    int gppx;
    int gppy;
};

struct SpaceCoords
{
    int gwspace = 10;
    int ghspace = 10;
};

struct MooshroomCoord
{
    int gmfx;
    int gmfy;

                    /* poisonous mooshroom part */

    int gmpx;
    int gmpy;
};

#endif