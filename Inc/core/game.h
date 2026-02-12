#ifndef _H_GAME
#define _H_GAME

#include <vector>
#include <deque>
#include <memory>
#include <future>

#include "character.h"
#include "task.h"
#include "systems/ThreadPool.h"
#include "systems/name_manager.h"

using namespace std;

// ======================================================
// Constants
// ======================================================

static const int    MAX_CHARACTERS = 30;
static const size_t MAX_MISSIONS   = 30;

// ======================================================
// Status
// ======================================================

enum class eAddStatus {
    SUCCESS,
    FULL,
    INVALID
};

// ======================================================
// Game Class
// ======================================================

class Game
{
private:
    string name;

    vector<unique_ptr<Character>> characters;
    deque<unique_ptr<Task>>       questQueue;
    ThreadPool           threadPool;
    vector<future<void>> activeFutures;
    size_t               nextCharacterIndex = 0;
    NameManager nameManager;  

public:
    explicit Game(string gameName = "MapleStory");
    ~Game();

    Game(const Game&)            = delete;
    Game& operator=(const Game&) = delete;
    Game(Game&&)                 = delete;
    Game& operator=(Game&&)      = delete;

    // ---- Characters ----
    bool       canAddCharacter() const;
    eAddStatus addCharacter(unique_ptr<Character> c);

    // ---- Quests ----
    bool       canAddQuest() const;
    eAddStatus addQuest(unique_ptr<Task> q);
    void       dispatchQuests();
    inline bool hasQuests() const { return !questQueue.empty(); }

    // ---- Flow ----
    void waitForAllQuests();

    // ---- Debug ----
    void printStatus() const;
    void printQuests() const;
    void printCharacters() const;
};

#endif // _H_GAME
