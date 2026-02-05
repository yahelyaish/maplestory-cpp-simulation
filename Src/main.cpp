#include <thread>
#include <chrono>
#include "game.h"
int main()
{
    Game g("MapleStory");
    g.printPlayers();
    g.executeMission();
    this_thread::sleep_for(std::chrono::seconds(5)); 
    g.printPlayers();
}