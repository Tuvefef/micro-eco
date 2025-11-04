#ifndef GAMESTRUCTS
#define GAMESTRUCTS

struct sCreatureCoord
{
    int plx;
    int ply;

    int pyx0;
    int pyy0;
};

struct sCreatureEnergy
{
    int generg = 200;
};

struct sPlantsCoord
{
    int psx;
    int psy;

    int ppx;
    int ppy;
};

#endif