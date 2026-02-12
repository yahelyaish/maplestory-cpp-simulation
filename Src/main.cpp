#include "core/game.h"
#include "core/task.h"
#include <mutex>
#include <iostream>
#include "systems/allocation_matrics.h"
#include "systems/timer.h"

using namespace std;
mutex g_console_mtx;

int main()
{
    Timer t;
    auto& m = AllocationMetrics::get();

    Game g("MapleStory");
    cout << "=== Initial Characters ===\n";
    g.printCharacters();
    while (g.hasQuests()) {
        g.dispatchQuests();
        g.waitForAllQuests();
    }

    cout << "\n=== Final Status ===\n";
    g.printCharacters();
    cout << "total allocations: "<<m.total()<<"\n";
    return 0;
}

//for counting allocations
void* operator new(size_t bytes) {
    AllocationMetrics::get().onAlloc(bytes);
    return malloc(bytes);
}
void operator delete(void* memory) noexcept
{
    free(memory);
}
void operator delete(void* memory, std::size_t) noexcept
{
    free(memory);
}