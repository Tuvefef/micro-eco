#include "splants.h"

void EdiblePlant::spawnPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space)
{
    do
    {
        plant.gpx = rand() % space.gwspace;
        plant.gpy = rand() % space.ghspace;
    } while(plant.gpx == crtr.gposx && plant.gpy == crtr.gposy);
}

void EdiblePlant::eatPlants(CreatureCoord& crtr, PlantCoord& plant, SpaceCoords& space)
{
    if(crtr.gposx == plant.gpx && crtr.gposy == plant.gpy)
    {
        crtr.genergy += 5;
        spawnPlants(crtr, plant, space);
    }
}