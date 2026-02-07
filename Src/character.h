#ifndef _H_CHARACTER
#define _H_CHARACTER

#include <string>
#include <iostream>
#include <mutex>
#include "configurations.h"

using namespace std;

// ======================================================
// Character Current State
// ======================================================

struct CharacterState {
    size_t level;
    size_t att;
    size_t def;
    int    hp;
    int    mp;
    size_t exp;
    size_t numOfKills;
};

// ======================================================
// Character Class
// ======================================================

class Character
{
protected:
    string name;
    eJobType job;
    CharacterState state;

    // Synchronization (optional – אפשר להוריד אם החלטת)
    mutable mutex states_mtx;

    virtual void toOs(ostream& os) const;

public:
    // ---- Ctors / Dtor ----
    Character() = delete;
    explicit Character(string name, eJobType job);
    virtual ~Character() = default;

    // ---- Getters (STATE בלבד) ----
    size_t getATT() const;
    size_t getDEF() const;
    int    getHP()  const;
    int    getMP()  const;

    size_t getLEVEL() const;
    size_t getEXP()   const;

    string getJobName() const;
    string getCharacterName() const { return name; }

    // ---- Game logic ----
    void setExp(size_t newExp);
    void levelUp();   // בלי פרמטרים

    // ---- Stream output ----
    friend ostream& operator<<(ostream& os, const Character& ch);
};

#endif // _H_CHARACTER
