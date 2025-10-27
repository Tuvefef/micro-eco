#include <iostream>
#include <vector>
#include <tuple>
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
    std::vector<std::tuple<int, int, std::string, std::string>> gentities = {
        {crtr.gposx, crtr.gposy, csys.blue(), "i "},
        {plant.gpx,  plant.gpy,  csys.cyan(), "* "},
        {plant.gppx, plant.gppy, csys.purple(), "* "},
        {npc.gposx,  npc.gposy,  csys.yellow(), "~ "},
        {predator.gposx, predator.gposy, csys.red(), "! "},
        {moosh0.gmfx, moosh0.gmfy, csys.yellow(), "m "},
        {moosh1.gmpx, moosh1.gmpy, csys.purple(), "m "},
        {moosh2.ghpx, moosh2.ghpy, csys.grey(), "m "}
    };

    for(int i0 = 0; i0 < space.ghspace; i0++)
    {
        for(int e0 = 0; e0 < space.gwspace; e0++)
        {
            bool drawn = false;
            for(auto& [ex, ey, color, symbol] : gentities)
            {
                if(e0 == ex && i0 == ey)
                {
                    std::cout << color << symbol << csys.reset() << std::flush;
                    drawn = true;
                    break;
                }
            }
            if(!drawn)
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
    EnergCreature energy;

    std::cout << csys.consoleclear();
    std::cout << "Welcome to the eco sim!\n";
    std::cout << "press enter to start...\n";

    
    std::cin.get();

    srand(time(nullptr));

    crtr.gposx = space.gwspace / 2;
    crtr.gposy = space.ghspace / 2;

    energy.genergy = IncMacros::INITENERG;

    //creature.spawnPrey(npc, crtr, space);
    incprey.creatureSpawn(crtr, npc, space);

    edplant.spawnPlants(crtr, plant, space);
    pplant.spawnPlants(crtr, plant, space);
    
    pmoosh.spawnMoosh(moosh1, crtr, space);
    smoosh.spawnMoosh(moosh0, crtr, space);
    hmoosh.spawnMoosh(moosh2, crtr, space);

    for(int gtck = 0; gtck < IncMacros::MAXTICKSGAME; gtck++)
    {
        std::cout << csys.consoleclear();
        std::cout << "ticks: " << gtck << "\n";

        std::cout << "energy: " << energy.genergy << "\n";

        if(gall.ishallucination) 
        {
            std::cout << "hallucination: " << gall.hallucinationTicks << "\n";
        }

        renderWord(csys, crtr, npc, plant, predator, space, pmoosh, smoosh, moosh0, moosh1, moosh2);

        incplayer.moveCreature(crtr, space, getInput(), energy);
        incplayer.playerLowenerg(energy);
        incprey.moveCreature(npc, space, rand() % 6, energy);
        incplayer.creatureEat(crtr, npc, space, energy);
        mpred.moveCreature(predator, space, rand() % 4, energy);
        mpred.creatureEat(crtr, predator, space, energy);

        smoosh.eatMoosh(crtr, moosh0, space, gall, energy);
        pmoosh.eatMoosh(crtr, moosh1, space, gall, energy);
        hmoosh.eatMoosh(crtr, moosh2, space, gall, energy);

        if(gall.ishallucination)
        {
            hmoosh.effectMoosh(crtr, gall);
            hmoosh.lowEffect(gall);
        }

        if(hmoosh.tickteffect(gall))
        {
            gall.ishallucination = false;
        }

        edplant.eatPlants(crtr, plant, space, energy);
        pplant.eatPlants(crtr, plant, space, energy);

        if(incplayer.playerDead(energy))
        {
            std::cout << "creature is dead!\n";
            break;
        }
    }
}