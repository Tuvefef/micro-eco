#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

#include "common/core/utils.hpp"
#include "common/core/structs.hpp"
#include "common/console.hpp"
#include "common/core/erand.h"

#include "common/eplant.hpp"
#include "common/eplayer.hpp"
#include "common/epreys.hpp"

void setNCursesBool(bool e)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if(!e)
        tty.c_lflag &= ~(ICANON | ECHO);
    else
        tty.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

char getkeys(void)
{
    char k;
    setNCursesBool(false);
    k = std::cin.get();
    setNCursesBool(true);
    return k;
}

void renderChars(sCreatureCoord &scc, sPlantsCoord &spc)
{
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            if(i == scc.ply && j == scc.plx)
                std::cout << console::grey << "i " << console::reset;
            else if(i == spc.psy && j == spc.psx)
                std::cout << console::cyan << "* " << console::reset;
            else if(i == spc.ppy && j == spc.ppx)
                std::cout << console::greenb << "* " << console::reset;
            else if(i == scc.pyy0 && j == scc.pyx0)
                std::cout << console::yellowb << "~ " << console::reset;
            else 
                std::cout << console::green << ". " << console::reset; 
        }
        std::cout << std::endl;
    }
}

int main()
{
    sCreatureCoord scc;
    sPlantsCoord spc;
    sCreatureEnergy sce;

    PlayerRender rplayer;
    PreyRender0 prey0;
    SafePlant splants;
    PoisonousPlant pplants;

    std::cout << console::consoleClean;
    std::cout << "welcome to micro eco!\n";
    std::cout << "press enter to star\n";
    std::cin.get();

    gSrand(time(nullptr));

    scc.plx = WIDTH / 2;
    scc.ply = HEIGHT / 2;

    prey0.creatureSpawn(scc);

    splants.spawnPlants(scc, spc);
    pplants.spawnPlants(scc, spc);

    for(int i = 0; i < TICKS; i++)
    {
        std::cout << console::consoleClean;
        std::cout << "ticks: " << i << std::endl;
        std::cout << "energy: " << sce.generg << std::endl;
        
        renderChars(scc, spc);
        rplayer.creatureMove(scc, &sce, getkeys());
        prey0.creatureMove(scc, nullptr, static_cast<int>(grmod(gprey0)));
        rplayer.creatureEat(scc, &sce);
        rplayer.playerLowEnerg(sce);

        splants.consumePlant(scc, spc, sce);
        pplants.consumePlant(scc, spc, sce);

        if(rplayer.playerDead(sce))
        {
            std::cout << "player is dead!\n";
            break;
        }
    }
    
}