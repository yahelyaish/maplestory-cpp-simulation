#ifndef _H_MAGICIAN
#define _H_MAGICIAN

#include "jobs/job.h"

class MagicianJob : public Job {
private:
    static constexpr Stats baseStats  = {14, 6,  8, 20};

    static constexpr Stats growthStats = {1, 1,  6, 15};
public:
    virtual ~MagicianJob() = default;


    virtual std::string getName() const override {return "MAGICIAN";}
    virtual void levelUP(Stats& stats) override {stats+=growthStats;}

    //after we add Equipments and etc the att and def will change

    // virtual size_t computeATT(const Stats& stats) const = 0;
    // virtual size_t computeDEF(const Stats& stats) const = 0;

    //after the character lvls up we can add JOBCHANGE and etc
    // virtual void onJobChange(Stats& stats) { }   // אם תרצה hook בעת החלפת Job
    // virtual unique_ptr<Job> clone() const = 0; // אם תשתמש ב-Prototype
};

#endif //_H_MAGICIAN
