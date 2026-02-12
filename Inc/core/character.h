#ifndef _H_CHARACTER
#define _H_CHARACTER

#include <iostream>
#include <memory>
#include <string>
#include <mutex>
#include "jobs/job.h"
#include "stats.h"



class Character {
protected:
    std::string name;
    size_t level = 1;
    size_t exp   = 0;
    Stats currentStats={10,10,10,10};
   // unique_ptr<Equipment> Equip;
    std::unique_ptr<Job> job;
    mutable std::mutex changeStates_mtx;
    size_t numOfKILLS = 0;//optional

public:
    Character(const std::string& n,std::unique_ptr<Job> theJob);

    virtual ~Character() = default;

    virtual size_t getATT() const;
    virtual size_t getDEF() const;

    // virtual size_t computeATT() const =0;
    // virtual size_t computeDEF() const =0;
    //virtual string getJobName();
    void levelUP();

   
    std::string getCharacterName() const { return name; }
    size_t getEXP() const { return exp; }
    size_t getLEVEL() const { return level; }

    void setExp(size_t newExp);
    
  friend std::ostream& operator<<(std::ostream& os, const Character& ch) {
    os << "=== Character Info ===\n"
       << "Name  : " << ch.name << "\n"
       << "Level : " << ch.level << "\n"
       << "EXP   : " << ch.exp<<"\\"<<ch.level*10<<"\n"
       << "Job   : " << ch.job->getName() << "\n"
       << "Stats : " << ch.currentStats << "\n";
    return os;
    }
};

#endif
