#ifndef ENTITYSTRUCTS
#define ENTITYSTRUCTS

#define MAXHALLUCINOGEN 10
#define HALLUCINOGENPROB 0.99

#define MAXPREYVAL 10
#define MPOISONOUSVAL 8
#define ENDENTITY 0

#define MAXTICKSGAME 300
#define INITENERG 50

struct CreatureCoord
{
    int gposx;
    int gposy;
    int genergy;
};

struct Hallucinogen
{
    bool ishallucination = false;
    int hallucinationTicks = 0;
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

    
                    /* hallucinogen */

    int ghpx;
    int ghpy;
};

enum IncCoords
{
    iccoorw = 0,
    iccoors = 1,
    iccoora = 2,
    iccoord = 3
};

#endif