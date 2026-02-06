#ifndef _H_GAME
#define _H_GAME
//total purpose of this game, is make characters, have a queue of tasks,
//and with threadpool the characters will accomplish the tasks.
//each task they do , they get more exp eventually they will level up.
//to sum up.. MAPLE STORY TIME
#include <iostream>
#include "character.h"
#include "team.h"
#include <memory>
#include <vector>
#include <queue>
#include "thiefTask.h"
#include "thief.h"
#include "ThreadPool.h"
#include <random>
#include <fstream>

using namespace std;

static const int MAX_CHARACTERS = 30;
static const size_t MAX_MISSIONS = 30;
#define CHARACTER_NAMES_FILE "character_names.txt"

enum class eAddStatus {
    SUCCESS,
    FULL,
    INVALID_CHARACTER
};

class Game{

    private:
    string name;
    deque<unique_ptr<Task>> missionQueue;
    vector<unique_ptr<Character>>characters;
    ThreadPool tPool;
    size_t nextCharacterIndex =0;
    vector<string> names;

    public:
    Game(string gameName="MapleStory");

    Game(const Game &other) = delete;
    Game& operator=(const Game& other) = delete;
    Game(Game&&other) = delete;
    Game& operator=(Game&& other) = delete;

    bool canAddMoreCharacters() const;
    eAddStatus addCharacter(unique_ptr<Character> c);

    bool canAddMoreMissions()const;
    eAddStatus addMission(unique_ptr<Task>t);

    void executeMission();

    void printStatus() const;
    void printMissions() const ;
    void printPlayers() const ;
    string pickRandomName(vector<string>& names);
    static vector<string> loadNamesFromFile(const string& filename);
    void setName(const string& name);
    void waitForMissions(){tPool.waitAll();}
    inline bool hasMissions() const {return !missionQueue.empty();}
};

#endif //_H_GAME