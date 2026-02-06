#include "task.h"
#include "character.h"
#include <chrono>
#include <ratio>
#include <thread>
#include <syncstream>
class ThiefTask:public Task{


    public:
    ThiefTask():Task("ThiefTask",10,10,200){};

    virtual bool canBeExecutedBy(const Character& c) const override{
        return (c.getATT()>=getDifficulty());
    }

    virtual void execute(Character& c)  override{
    int attacking = c.getATT();

    if (attacking <= 0)
        return;

    while (lifeTime > 0) {
        lifeTime -= attacking;
    }
    c.setExp(getRewardEXP());
    {
        unique_lock<mutex> lock(g_console_mtx);
        cout << c.getCharacterName()
             << " finish executing task number: "
             << getTaskID() << endl;
    }
}
};