#ifndef GAMESTRUCTS
#define GAMESTRUCTS

struct sCreatureCoord
{
    int plx;
    int ply;

    int pyx0;
    int pyy0;
    int pyx1;
    int pyy1;

    int prx0;
    int pry0;
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

struct MushroomCoord
{
    int msx;
    int msy;
    int mtx;
    int mty;
    int mhx;
    int mhy;
};

struct Hallucinogen
{
    int hticks = 0;
    bool isHallucination = false;
};

struct RocksCoord
{
    int rx;
    int ry;
};

#endif