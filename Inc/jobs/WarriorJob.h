#ifndef _H_WARRIOR
#define _H_WARRIOR


#include "jobs/job.h"

class WarriorJob : public Job {
private:
    static constexpr Stats baseStats  = {22,15, 18,  4};
    static constexpr Stats growthStats = {2, 3, 18,  2};
public:
    virtual ~WarriorJob() = default;


    virtual std::string getName() const override {return "WARRIOR";}
    virtual void levelUP(Stats& stats) override {stats+=growthStats;}

    //after we add Equipments and etc the att and def will change

    // virtual size_t computeATT(const Stats& stats) const = 0;
    // virtual size_t computeDEF(const Stats& stats) const = 0;

    //after the character lvls up we can add JOBCHANGE and etc
    // virtual void onJobChange(Stats& stats) { }   // אם תרצה hook בעת החלפת Job
    // virtual unique_ptr<Job> clone() const = 0; // אם תשתמש ב-Prototype
};

#endif //_H_WARRIOR
