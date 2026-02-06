#ifndef _TASK_H
#define _TASK_H
#include "character.h"
#include <iostream>
#include <string>
#include <mutex>
using namespace std;

extern mutex g_console_mtx;
class Task {
protected:
    string name;
    size_t difficulty;
    size_t rewardEXP;
    int lifeTime;
    size_t taskID;


    inline static size_t nextTaskID = 1;   // ✅ מונה יחיד ובטוח

public:
    virtual ~Task() = default;

    size_t getTaskID() const { return taskID; }
    const string& getName() const { return name; }
    size_t getDifficulty() const { return difficulty; }
    size_t getRewardEXP() const { return rewardEXP; }
    size_t getLifeTime() const { return lifeTime; }

    virtual bool canBeExecutedBy(const Character& c) const = 0;
    virtual void execute(Character& c)  = 0;

    void print() const {
        cout << "\nTask ID: " << taskID
             << "\nName: " << name
             << "\nDifficulty: " << difficulty
             << "\nLifeTime: " << lifeTime
             << "\nRewardEXP: " << rewardEXP << endl;
    }

protected:
    Task(const string& name = "defaultTask",
         size_t difficulty = 10,
         size_t rewardEXP = 10,
         size_t lifeTime = 20)
        : name(name),
          difficulty(difficulty),
          rewardEXP(rewardEXP),
          lifeTime(lifeTime),
          taskID(nextTaskID++) 
    {}
};

#endif //_TASK_H
