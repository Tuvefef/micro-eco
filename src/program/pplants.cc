#include "pplants.h"

void PoisonousPlant::spawnPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space)
{
    do
    {
        plant.gppx = rand() % space.gwspace;
        plant.gppy = rand() % space.ghspace;
    } while((plant.gppx == crtr.gposx && plant.gppy == crtr.gposy) || (plant.gppx == plant.gpx && plant.gppy == plant.gpy));
}

void PoisonousPlant::eatPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space)
{
    if(crtr.gposx == plant.gppx && crtr.gposy == plant.gppy)
    {
        crtr.genergy -= 3;
        spawnPlants(crtr, plant, space);
    }
}