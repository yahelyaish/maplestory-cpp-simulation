#ifndef _H_THIEF
#define _H_THIEF

#include "jobs/job.h"

class ThiefJob : public Job {
private:
    static constexpr Stats baseStats  = {18, 8, 12, 8};
    static constexpr Stats growthStats = {2, 3, 10, 5};

public:
    ThiefJob() =  default;
    virtual ~ThiefJob() = default;


    virtual std::string getName() const override {return "THIEF";}
    virtual void levelUP(Stats& stats) override {stats+=growthStats;}

    //after we add Equipments and etc the att and def will change

    // virtual size_t computeATT(const Stats& stats) const = 0;
    // virtual size_t computeDEF(const Stats& stats) const = 0;

    //after the character lvls up we can add JOBCHANGE and etc
    // virtual void onJobChange(Stats& stats) { }   // אם תרצה hook בעת החלפת Job
    // virtual unique_ptr<Job> clone() const = 0; // אם תשתמש ב-Prototype
};

#endif
