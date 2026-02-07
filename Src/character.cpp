#include "character.h"
#include "configurations.h"

// ======================================================
// Ctor
// ======================================================

Character::Character(string name, eJobType job)
    : name(std::move(name)), job(job)
{
    JobProfile base = getJobProfile(job);

    state.level = 1;
    state.att   = base.baseAttack;
    state.def   = base.baseDefence;
    state.hp    = base.baseHP;
    state.mp    = base.baseMP;
    state.exp   = 0;
    state.numOfKills = 0;
}

// ======================================================
// Printing
// ======================================================

void Character::toOs(ostream& os) const
{
    os << "\nName: " << name
       << "\nJob: " << getJobName()
       << "\nLevel: " << state.level
       << "\nEXP: " << state.exp
       << "\nATT: " << state.att
       << "\nDEF: " << state.def
       << "\nHP: " << state.hp
       << "\nMP: " << state.mp
       << "\nKills: " << state.numOfKills
       << endl;
}

ostream& operator<<(ostream& os, const Character& ch)
{
    ch.toOs(os);
    return os;
}

// ======================================================
// Getters (STATE בלבד)
// ======================================================

size_t Character::getATT() const { return state.att; }
size_t Character::getDEF() const { return state.def; }
int    Character::getHP()  const { return state.hp;  }
int    Character::getMP()  const { return state.mp;  }

size_t Character::getLEVEL() const { return state.level; }
size_t Character::getEXP()   const { return state.exp;   }

string Character::getJobName() const
{
    return JobSTR[static_cast<int>(job)];
}

// ======================================================
// Game Logic
// ======================================================

void Character::setExp(size_t newExp)
{
    state.exp += newExp;
    state.numOfKills++;

    while (state.exp >= state.level * 10) {
        state.exp -= state.level * 10;
        levelUp();
    }
}

void Character::levelUp()
{
    JobGrowth growth = getJobGrowth(job);

    state.att += growth.attPerLevel;
    state.def += growth.defPerLevel;
    state.hp  += growth.hpPerLevel;
    state.mp  += growth.mpPerLevel;
    state.level++;
}
