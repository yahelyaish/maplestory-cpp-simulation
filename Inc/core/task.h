#ifndef _TASK_H
#define _TASK_H

#include <string>
#include <mutex>

#include "character.h"
#include "monsters/monsters.h"
using namespace std;

extern mutex g_console_mtx;

// ======================================================
// Task / Quest
// Represents a monster-hunting quest
// ======================================================




class Task
{
protected:
    string      name;
    MonsterRank monsterRank;
    size_t      taskID;
    int         currentHP;

    inline static size_t nextTaskID = 1;

public:
    // ---- Ctor / Dtor ----
    Task(const string& name, MonsterRank rank)
        : name(name), monsterRank(rank),taskID(++nextTaskID),currentHP(getMonsterHP()) {}

    virtual ~Task() = default;

    // ---- Getters ----
    size_t      getTaskID()   const { return taskID; }
    const string& getName()   const { return name; }
    MonsterRank getMonsterRank() const { return monsterRank; }

    size_t getRewardEXP() const;
    int    getMonsterHP() const;

    // ---- Gameplay ----
    virtual bool canBeExecutedBy(const Character& c) const;
    virtual void execute(Character& c);

    // ---- Debug ----
    void print() const;
};

#endif // _TASK_H
