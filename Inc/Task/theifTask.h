#include "task.h"
#include "character.h"
#include <chrono>
#include <mutex>
#include <ratio>
#include <thread>
class Character;
class TheifTask:public Task{

    public:
    TheifTask():Task("theifTask",10,10,200){};

    virtual bool canBeExecutedBy(const Character& c) const override{
        return (c.getATT()>=getDifficulty());
    }

    virtual void execute(Character& c) const override{
        size_t attacking = (size_t)c.getATT();
        size_t tmp_lifeTime =getLifeTime();
        while (tmp_lifeTime > 0) {
        tmp_lifeTime -= attacking;
        if(tmp_lifeTime==0){
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
        }
        c.setExp(getRewardEXP());//adding EXP to the character
        }
};