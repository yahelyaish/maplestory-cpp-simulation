#include "core/character.h"
#include "jobs/job.h"
using namespace std;

// ======================================================
// Printing
// ======================================================

Character::Character(const string& n,unique_ptr<Job> theJob):name(n),job(std::move(theJob)){}

size_t Character::getATT() const
{
    lock_guard<mutex> lock(changeStates_mtx);
    return currentStats.attack;
}

size_t Character::getDEF() const
{
    lock_guard<mutex> lock(changeStates_mtx);
        return currentStats.defense;
}


// ======================================================
// EXP Logic
// ======================================================

void Character::setExp(size_t newExp)
{
    {
        unique_lock<mutex> lock(changeStates_mtx);
        exp += newExp;
        numOfKILLS++;

        while (exp >= level * 10) {
        exp -= level * 10;

        levelUP();
        cout << name << " leveled up to level "
             << level << "!\n";
    }
}
}

void Character::levelUP() {
    level++;
    job->levelUP(currentStats);
}
