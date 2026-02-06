#include "game.h"

mutex g_console_mtx;

int main()
{
    Game g("MapleStory");
    g.printPlayers();

    while (g.hasMissions()) {
        g.executeMission();    
        g.waitForMissions();  
    }

    cout << "STATUS:\n";
    g.printPlayers();
}