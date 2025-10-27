#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <algorithm>

#include "program/console.h"
#include "program/splants.h"
#include "program/pplants.h"
#include "program/smoosh.h"
#include "program/pmoosh.h"
#include "program/structs.h"
#include "program/sysmath.h"
#include "program/rplayer.h"
#include "program/rcreature.h"
#include "program/hmoosh.h"

void setNCursesBool(bool enable)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if(!enable)
        tty.c_lflag &= ~(ICANON | ECHO);
    else
        tty.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

char getInput()
{
    setNCursesBool(false);
    char x = std::cin.get();
    setNCursesBool(true);
    return x;
}

void renderWord(Consoleformat& csys, CreatureCoord& crtr, CreatureCoord& npc, PlantCoord& plant, CreatureCoord& predator, SpaceCoords& space, PoisonousMoosh& pmoosh, SafeMoosh& smoosh, MooshroomCoord& moosh0, MooshroomCoord& moosh1, MooshroomCoord& moosh2)
{
    for(int i0 = 0; i0 < space.ghspace; i0++)
    {
        for(int e0 = 0; e0 < space.gwspace; e0++)
        {
            if(e0 == crtr.gposx && i0 == crtr.gposy)
                std::cout << csys.blue() << "i " << csys.reset() << std::flush;
            else if(e0 == plant.gpx && i0 == plant.gpy)
                std::cout << csys.cyan() << "* " << csys.reset() << std::flush;
            else if(e0 == plant.gppx && i0 == plant.gppy)
                std::cout << csys.purple() << "* " << csys.reset() << std::flush;
            else if(e0 == npc.gposx && i0 == npc.gposy)
                std::cout << csys.yellow() << "~ " << csys.reset() << std::flush;
            else if(e0 == predator.gposx && i0 == predator.gposy)
                std::cout << csys.red() << "! " << csys.reset() << std::flush;
            else if(e0 == moosh0.gmfx && i0 == moosh0.gmfy)
                std::cout << csys.yellow() << "m " << csys.reset() << std::flush;
            else if(e0 == moosh1.gmpx && i0 == moosh1.gmpy)
                std::cout << csys.purple() << "m " << csys.reset() << std::flush;
            else if(e0 == moosh2.ghpx && i0 == moosh2.ghpy)
                std::cout << csys.grey() << "m " << csys.reset() << std::flush;
            else
                std::cout << csys.green() << ". " << csys.reset() << std::flush;
        }
        std::cout << std::endl;
    }
}

int main()
{
    //class instance
    Consoleformat csys;
    SafeMoosh smoosh;
    PoisonousMoosh pmoosh;
    HallucinogenMoosh hmoosh;

    EdiblePlant edplant;
    PoisonousPlant pplant;

    RenderPlayer incplayer;
    RenderPrey incprey;
    RenderPredator mpred;

    //struct instances
    CreatureCoord crtr;
    CreatureCoord npc;
    CreatureCoord predator;
    PlantCoord plant;
    SpaceCoords space;
    MooshroomCoord moosh0;
    MooshroomCoord moosh1;
    MooshroomCoord moosh2;
    Hallucinogen gall;

    std::cout << csys.consoleclear();
    std::cout << "Welcome to the eco sim!\n";
    std::cout << "press enter to start...\n";

    
    std::cin.get();

    srand(time(nullptr));

    crtr.gposx = space.gwspace / 2;
    crtr.gposy = space.ghspace / 2;
    crtr.genergy = INITENERG;

    //creature.spawnPrey(npc, crtr, space);
    incprey.creatureSpawn(crtr, npc, space);

    edplant.spawnPlants(crtr, plant, space);
    pplant.spawnPlants(crtr, plant, space);
    
    pmoosh.spawnMoosh(moosh1, crtr, space);
    smoosh.spawnMoosh(moosh0, crtr, space);
    hmoosh.spawnMoosh(moosh2, crtr, space);

    for(int gtck = 0; gtck < MAXTICKSGAME; gtck++)
    {
        std::cout << csys.consoleclear();
        std::cout << "ticks: " << gtck << "\n";

        std::cout << "energy: " << crtr.genergy << "\n";

        renderWord(csys, crtr, npc, plant, predator, space, pmoosh, smoosh, moosh0, moosh1, moosh2);

        incplayer.moveCreature(crtr, space, getInput());
        incplayer.playerLowenerg(crtr);
        incprey.moveCreature(npc, space, rand() % 6);
        incplayer.creatureEat(crtr, npc, space);
        mpred.moveCreature(predator, space, rand() % 4);
        mpred.creatureEat(crtr, predator, space);

        smoosh.eatMoosh(crtr, moosh0, space, gall);
        pmoosh.eatMoosh(crtr, moosh1, space, gall);
        hmoosh.eatMoosh(crtr, moosh2, space, gall);

        if(gall.ishallucination)
        {
            hmoosh.effectMoosh(crtr, gall);
            hmoosh.lowEffect(gall);
        }

        if(hmoosh.tickteffect(gall))
        {
            gall.ishallucination = false;
        }

        edplant.eatPlants(crtr, plant, space);
        pplant.eatPlants(crtr, plant, space);

        if(incplayer.playerDead(crtr))
        {
            std::cout << "creature is dead!\n";
            break;
        }
    }
}