#ifndef _CONFIGURATIONS_H
#define _CONFIGURATIONS_H

#include <string>
using namespace std;

// ======================================================
// Monsters (Tasks)
// ======================================================

enum class MonsterRank {
    SLIME = 0,
    WILD_BOAR,
    STONE_GOLEM,
    DRAGON,
    RANK_COUNT
};

struct MonsterProfile {
    size_t minATT;     // מינימום התקפה כדי להילחם
    size_t rewardEXP;  // EXP שמתקבל
    int    baseHP;     // "חיים" של המפלצת
};

extern const string MonsterRankSTR[];
MonsterProfile getMonsterProfile(MonsterRank rank);

// ======================================================
// Jobs (Characters)
// ======================================================

enum class eJobType {
    THIEF = 0,
    MAGICIAN,
    ARCHER,
    WARRIOR,
    JOB_COUNT
};

extern const string JobSTR[];

struct JobProfile {
    size_t baseAttack;
    size_t baseDefence;
    int    baseHP;
    int    baseMP;
};

struct JobGrowth {
    size_t attPerLevel;
    size_t defPerLevel;
    int    hpPerLevel;
    int    mpPerLevel;
};

JobProfile getJobProfile(eJobType job);
JobGrowth  getJobGrowth(eJobType job);

// ======================================================
// Assets (Name files)
// ======================================================

constexpr const char* JOB_NAME_FILES[] = {
    "./names/thief.txt",
    "./names/magician.txt",
    "./names/archer.txt",
    "./names/warrior.txt"
};

string getFileNameJobs(eJobType job);

#endif // _CONFIGURATIONS_H
