#include "configurations.h"

// ======================================================
// Monster Configurations
// ======================================================

const string MonsterRankSTR[] = {
    "Slime",
    "Wild Boar",
    "Stone Golem",
    "Dragon"
};

MonsterProfile getMonsterProfile(MonsterRank rank)
{
    if (rank == MonsterRank::SLIME)
        return {10,  8,   60};
    else if (rank == MonsterRank::WILD_BOAR)
        return {18, 18,  180};
    else if (rank == MonsterRank::STONE_GOLEM)
        return {26, 40,  450};
    else if (rank == MonsterRank::DRAGON)
        return {40,120, 1200};

    return {999999, 0, 0};
}

// ======================================================
// Job Base Stats
// ======================================================

const string JobSTR[] = {
    "THIEF",
    "MAGICIAN",
    "ARCHER",
    "WARRIOR"
};

JobProfile getJobProfile(eJobType job)
{
    if (job == eJobType::THIEF)
        return {18, 8, 12,  8};
    else if (job == eJobType::ARCHER)
        return {16, 7, 10,  6};
    else if (job == eJobType::WARRIOR)
        return {22,15, 18,  4};
    else if (job == eJobType::MAGICIAN)
        return {14, 6,  8, 20};

    return {0,0,0,0};
}

// ======================================================
// Job Growth Per Level
// ======================================================

JobGrowth getJobGrowth(eJobType job)
{
    if (job == eJobType::THIEF)
        return {2, 3, 10,  5};
    else if (job == eJobType::ARCHER)
        return {3, 1,  8,  4};
    else if (job == eJobType::WARRIOR)
        return {2, 3, 18,  2};
    else if (job == eJobType::MAGICIAN)
        return {1, 1,  6, 15};

    return {0,0,0,0};
}

// ======================================================
// Job → Name file mapping
// ======================================================

string getFileNameJobs(eJobType job)
{
    return JOB_NAME_FILES[static_cast<int>(job)];
}
