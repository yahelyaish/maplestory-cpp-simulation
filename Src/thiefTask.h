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

    virtual void execute(Character& c) const override{
        size_t attacking = c.getATT(); //changing ATT while lvling up its problematic
        size_t tmp_lifeTime =getLifeTime();


        while (tmp_lifeTime > 0) {
        tmp_lifeTime -= attacking;
        if(tmp_lifeTime==0){
            break;
        }
       //  this_thread::sleep_for(chrono::milliseconds(100));
        }
        c.setExp(getRewardEXP());
        {
        unique_lock<mutex>lock(g_console_mtx);
        cout<<c.getCharacterName()<<" finish executing task number: "<<getTaskID()<<endl;
        }

        }
};