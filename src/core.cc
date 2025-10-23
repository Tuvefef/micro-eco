#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <algorithm>

#include "program/consoleFormat.h"
#include "program/creature.h"
#include "program/plants.h"
#include "program/structs.h"
#include "program/sysmath.h"

#define gw0 10
#define gh0 10
#define gTicks 300
#define defEnergy 50

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

void renderWord(Consoleformat& csys, CreatureCoord& crtr, CreatureCoord& npc, PlantCoord& plant, PoisonousPlantCoord& pplant, CreatureCoord& predator)
{
    for(int i0 = 0; i0 < gh0; i0++)
    {
        for(int e0 = 0; e0 < gw0; e0++)
        {
            if(e0 == crtr.gposx && i0 == crtr.gposy)
                std::cout << csys.blue() << "i " << csys.reset() << std::flush;
            else if(e0 == plant.gpx && i0 == plant.gpy)
                std::cout << csys.cyan() << "* " << csys.reset() << std::flush;
            else if(e0 == pplant.gppx && i0 == pplant.gppy)
                std::cout << csys.purple() << "x " << csys.reset() << std::flush;
            else if(e0 == npc.gposx && i0 == npc.gposy)
                std::cout << csys.yellow() << "~ " << csys.reset() << std::flush;
            else if(e0 == predator.gposx && i0 == predator.gposy)
                std::cout << csys.red() << "! " << csys.reset() << std::flush;
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
    RenderCreature creature;

    //struct instances
    CreatureCoord crtr;
    CreatureCoord npc;
    CreatureCoord predator;
    PlantCoord plant;
    PoisonousPlantCoord pplant;

    std::cout << csys.consoleclear();
    std::cout << "Welcome to the eco sim!\n";
    std::cout << "press enter to start...\n";

    
    std::cin.get();

    srand(time(nullptr));

    crtr.gposx = gw0 / 2;
    crtr.gposy = gh0 / 2;
    crtr.genergy = defEnergy;

    creature.spawnPrey(npc, crtr);

    Plant plant0;
    plant0.spawnPlant(crtr, plant);
    plant0.spawnPoisonousPlant(crtr, plant, pplant);

    for(int gtck = 0; gtck < gTicks; gtck++)
    {
        std::cout << csys.consoleclear();
        std::cout << "ticks: " << gtck << "\n";

        std::cout << "energy: " << crtr.genergy << "\n";

        renderWord(csys, crtr, npc, plant, pplant, predator);
        creature.renderPlayermove(crtr, plant0, plant, pplant, getInput());
        creature.creatureEatPlant(crtr, plant0, plant, pplant);
        creature.creaturealowenerg(crtr);
        creature.preyCreature(npc);
        creature.eatPrey(crtr, npc);
        creature.predatorCreature(predator);
        creature.eatPlayer(crtr, predator);

        if(creature.creatureDead(crtr))
        {
            std::cout << "creature is dead!\n";
            break;
        }
        //std::cin.get();
    }
}