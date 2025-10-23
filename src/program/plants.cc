#include "plants.h"

void Plant::spawnPlant(CreatureCoord& crtr, PlantCoord& plant0)
{
    do 
    {
        plant0.gpx = rand() % 10;
        plant0.gpy = rand() % 10;
    } while(plant0.gpx == crtr.gposx && plant0.gpy == crtr.gposy);
}

void Plant::spawnPoisonousPlant(CreatureCoord& crtr, PlantCoord& plant0, PoisonousPlantCoord& pplant)
{
    do 
    {
        pplant.gppx = rand() % 10;
        pplant.gppy = rand() % 10;
    } while((pplant.gppx == crtr.gposx && pplant.gppy == crtr.gposy) || (pplant.gppx == plant0.gpx && pplant.gppy == plant0.gpy));  
}