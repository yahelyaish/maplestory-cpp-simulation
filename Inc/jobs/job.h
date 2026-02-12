#ifndef _H_JOB
#define _H_JOB

#include "core/stats.h"
class Job {
public:
    virtual ~Job() = default;

    virtual std::string getName() const = 0;

    virtual void levelUP(Stats& stats) = 0;

    //virtual void toOs(ostream& os) const=0;


    //to do list after we add equips+possibility to change job's pointer.
    // ----- Combat Calculation -----
    // virtual size_t computeATT(const Stats& stats) const = 0;
    // virtual size_t computeDEF(const Stats& stats) const = 0;

    // ----- Optional Extensions -----
   // virtual void onJobChange(Stats& stats) { }   // אם תרצה hook בעת החלפת Job
   // virtual unique_ptr<Job> clone() const = 0; // אם תשתמש ב-Prototype
};

#endif
