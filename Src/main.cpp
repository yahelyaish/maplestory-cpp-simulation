#include "game.h"

mutex g_console_mtx;

int main()
{
    Game g("MapleStory");
    g.printPlayers();

    while (g.hasMissions()) {
        g.executeMission();   // משגר batch
        g.waitForMissions();  // מחכה שיסתיים
    }

    cout << "STATUS:\n";
    g.printPlayers();
}