#include "task.h"
#include "character.h"
#include <thread>
class MagicianTask:public Task{

    protected:
    MagicianTask():Task("magicianTask",200,10,20){};

    virtual bool canBeExecutedBy(const Character& c) const override{
        return (c.getATT()>=getDifficulty());
    }

    virtual void execute(Character& c)  override{
        size_t attacking = (size_t)c.getATT();
        size_t tmp_difficulty = getDifficulty();
        while (tmp_difficulty > 0) {
        tmp_difficulty -= attacking;
        this_thread::sleep_for(chrono::seconds(1));
        }
        cout<<c.getJobName()<<" finish executing"<<endl;
    }

};