#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <algorithm>
#include <vector>

#include "common/core/utils.hpp"
#include "common/core/structs.hpp"
#include "common/core/grand.h"
#include "common/console.hpp"

#include "common/eplant.hpp"
#include "common/eplayer.hpp"
#include "common/epreys.hpp"
#include "common/epred.hpp"
#include "common/safemush.hpp"
#include "common/toxicmush.hpp"
#include "common/hallmush.hpp"

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

void renderChars(sCreatureCoord &scc, sPlantsCoord &spc, MushroomCoord &m, const std::vector<RocksCoord> &grock)
{
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {

            if(std::any_of(grock.begin(), grock.end(), [&](RocksCoord r){
                return i == r.ry && j == r.rx;
            }))
                std::cout << console::grey << "@ " << console::reset;
            else if(i == scc.ply && j == scc.plx)
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
            else if(i == m.mty && j == m.mtx)
                std::cout << console::grey << "m " << console::reset;
            else if(i == m.mhy && j == m.mhx)
                std::cout << console::purple << "m " << console::reset;
            else if(i == scc.pyx1 && j == scc.pyy1)
                std::cout << console::grey << "% " << console::reset;
            else 
                std::cout << console::green << ". " << console::reset; 
        }
        std::cout << std::endl;
    }
}

void renderRocks(std::vector<RocksCoord> &grock, int x, int y)
{
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            grock.push_back({x + i, y + j});
}

int main()
{
    sCreatureCoord scc;
    sPlantsCoord spc;
    sCreatureEnergy sce;
    MushroomCoord m;
    Hallucinogen h;
    std::vector<RocksCoord> grock;

    renderRocks(grock, 9, 9);
    renderRocks(grock, 2, 3);

    PlayerRender rplayer(scc, sce, spc, m, grock);
    PreyRender0 prey0(spc, scc, sce, m, grock);
    PreyRender1 prey1(spc, scc, sce, m, grock);
    PredatorRender0 pred0(scc, sce, spc, m, grock);
    SafePlant splants(scc, sce, spc);
    PoisonousPlant pplants(scc, sce, spc);
    SafeMushroom sm(scc, spc, sce, m, grock);
    ToxicMushroom tm(scc, sce, m, grock);
    HallucinogenMushroom hm(scc, sce, m, spc, h);

    std::cout << console::consoleClean;
    std::cout << "welcome to micro eco!\n";
    std::cout << "press enter to star\n";
    std::cin.get();

    gsrand(time(nullptr));

    scc.plx = WIDTH / 2;
    scc.ply = HEIGHT / 2;

    prey0.creatureSpawn();
    prey1.creatureSpawn();
    pred0.creatureSpawn();

    splants.spawnPlants();
    pplants.spawnPlants();

    sm.spawnMush();
    tm.spawnMush();
    hm.spawnMush();

    for(int i = 0; i < TICKS; i++)
    {
        std::cout << console::consoleClean;
        std::cout << "ticks: " << i << std::endl;
        std::cout << "energy: " << sce.generg << std::endl;
        
        renderChars(scc, spc, m, grock);
        
        rplayer.creatureMove(getkeys());
        prey0.creatureMove(static_cast<int>(grmod(5)));
        prey1.creatureMove(static_cast<int>(grmod(5)));
        pred0.creatureMove(static_cast<int>(grmod(4)));

        rplayer.creatureEat();
        prey0.eat();
        prey1.eat();
        pred0.creatureEat();
        rplayer.playerLowEnerg();

        splants.consumePlant();
        pplants.consumePlant();
        sm.consumeMush();
        tm.consumeMush();
        hm.consumeMush();

        if(h.isHallucination)
        {
            hm.effectMush();
            hm.low();
        }

        if(hm.ticks())
        {
            h.isHallucination = false;
        }

        if(rplayer.playerDead())
        {
            std::cout << "player is dead!\n";
            break;
        }
    }
    
}