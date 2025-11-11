#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

#include "common/core/utils.hpp"
#include "common/core/structs.hpp"
#include "common/core/grand.h"
#include "common/console.hpp"

#include "common/eplant.hpp"
#include "common/eplayer.hpp"
#include "common/epreys.hpp"
#include "common/epred.hpp"
#include "common/safemush.hpp"

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

void renderChars(sCreatureCoord &scc, sPlantsCoord &spc, MushroomCoord &m)
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
            else if(i == scc.pry0 && j == scc.prx0)
                std::cout << console::redb << "? " << console::reset;
            else if(i == m.msy && j == m.msx)
                std::cout << console::yellow << "m " << console::reset;
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
    MushroomCoord m;

    PlayerRender rplayer(scc, sce, spc);
    PreyRender0 prey0(spc, scc, sce);
    PredatorRender0 pred0(scc, sce, spc);
    SafePlant splants(scc, sce, spc);
    PoisonousPlant pplants(scc, sce, spc);
    SafeMushroom sm(scc, spc, sce, m);

    std::cout << console::consoleClean;
    std::cout << "welcome to micro eco!\n";
    std::cout << "press enter to star\n";
    std::cin.get();

    gsrand(time(nullptr));

    scc.plx = WIDTH / 2;
    scc.ply = HEIGHT / 2;

    prey0.creatureSpawn();
    pred0.creatureSpawn();

    splants.spawnPlants();
    pplants.spawnPlants();

    sm.spawnMush();

    for(int i = 0; i < TICKS; i++)
    {
        std::cout << console::consoleClean;
        std::cout << "ticks: " << i << std::endl;
        std::cout << "energy: " << sce.generg << std::endl;
        
        renderChars(scc, spc, m);
        
        rplayer.creatureMove(getkeys());
        prey0.creatureMove(static_cast<int>(grmod(5)));
        pred0.creatureMove(static_cast<int>(grmod(4)));

        rplayer.creatureEat();
        prey0.eatPlant();
        pred0.creatureEat();
        rplayer.playerLowEnerg();

        splants.consumePlant();
        pplants.consumePlant();
        sm.consumeMush();

        if(rplayer.playerDead())
        {
            std::cout << "player is dead!\n";
            break;
        }
    }
    
}