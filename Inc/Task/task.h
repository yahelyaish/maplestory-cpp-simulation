#include "character.h"
#include <iostream>
using namespace std;
#include <string>


class Task{
    protected:
    string name;
    size_t difficulty;
    size_t RewardEXP;
    size_t lifeTime;

    public:
    virtual ~Task() = default;
    inline const string& getName()const  {return name;}
    inline size_t getDifficulty()const {return difficulty;}
    inline size_t getRewardEXP()const {return RewardEXP;}
    inline size_t getLifeTime()const {return lifeTime;}

    virtual bool canBeExecutedBy(const Character& c) const = 0;
    virtual void execute(Character& c) const = 0;
    void print()const{
       cout<<"\nName: "<<name
       <<"\ndifficulty : "<<difficulty
       <<"\nlifeTime: "<<lifeTime
       <<"\nRewardEXP: "<<RewardEXP<<endl;
    }
    protected:
    Task();
    Task(string name):name(name){}
    
    Task(string name="defaultTask", int difficulty=10, int rewardExp=10,size_t lifeTime=20)
    :name(name),difficulty(difficulty),RewardEXP(rewardExp),lifeTime(lifeTime){}

};