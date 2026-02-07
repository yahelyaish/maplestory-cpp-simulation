#include "game.h"
#include <mutex>
#include <iostream>

using namespace std;

mutex g_console_mtx;

int main()
{
    Game g("MapleStory");

    cout << "=== Initial Characters ===\n";
    g.printCharacters();

    while (g.hasQuests()) {
        g.dispatchQuests();
        g.waitForAllQuests();
    }

    cout << "\n=== Final Status ===\n";
    g.printCharacters();

    return 0;
}
