#ifndef _H_GAME
#define _H_GAME
//total purpose of this game, is make characters, have a queue of tasks,
//and with threadpool the characters will accomplish the tasks.
//each task they do , they get more exp eventually they will level up.
//to sum up.. MAPLE STORY TIME
#include <iostream>
using namespace std;
#include "character.h"
#include "team.h"
#include <memory>
#include <vector>
#include <queue>
#include "theifTask.h"
#include "theif.h"
#include "ThreadPool.h"

static const int MAX_CHARACTERS = 9;
static const size_t MAX_MISSIONS = 20;


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

};

#endif //_H_GAME