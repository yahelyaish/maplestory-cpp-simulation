#ifndef _H_ARCHER
#define _H_ARCHER

#include "jobs/job.h"
class ArcherJob : public Job {
private:
    static constexpr Stats baseStats  = {16, 7, 10,  6};
    static constexpr Stats growthStats = {3, 1,  8,  4};
public:
    virtual ~ArcherJob() = default;


    virtual std::string getName() const override {return "ARCHER";}
    virtual void levelUP(Stats& stats) override {stats+=growthStats;}

    //after we add Equipments and etc the att and def will change

    // virtual size_t computeATT(const Stats& stats) const = 0;
    // virtual size_t computeDEF(const Stats& stats) const = 0;

    //after the character lvls up we can add JOBCHANGE and etc
    // virtual void onJobChange(Stats& stats) { }   // אם תרצה hook בעת החלפת Job
    // virtual unique_ptr<Job> clone() const = 0; // אם תשתמש ב-Prototype
};

#endif //_H_ARCHER
