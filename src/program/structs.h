#ifndef ENTITYSTRUCTS
#define ENTITYSTRUCTS

#include <cstdint>

namespace IncMacros
{
    inline constexpr std::int32_t MAXHALLUCINOGEN = 10;
    inline constexpr double HALLUCINOGENPROB = 0.99;

    inline constexpr std::int32_t MAXPREYVAL = 10;
    inline constexpr std::int32_t MPOISONOUSVAL = 8;
    inline constexpr std::int32_t ENDENTITY = 0;

    inline constexpr std::int32_t MAXTICKSGAME = 300;
    inline constexpr std::int32_t INITENERG = 50;

    inline constexpr std::int32_t PREY0ENERG = 20;
    inline constexpr std::int32_t PRED0ENERG = 20;
};

struct CreatureCoord
{
    int gposx;
    int gposy;
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

struct EnergCreature
{
    int geprey;
    int gepred;
    int genergy;
};

enum IncCoords 
{
    iccoorw = 0,
    iccoors = 1,
    iccoora = 2,
    iccoord = 3
};

#endif