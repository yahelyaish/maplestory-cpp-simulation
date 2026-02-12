#ifndef _MONSTER_H
#define _MONSTER_H
#include <string>

enum class MonsterRank {
    SLIME = 0,
    WILD_BOAR,
    STONE_GOLEM,
    DRAGON,
    RANK_COUNT
};

const std::string MonsterRankSTR[] = {
    "Slime",
    "Wild Boar",
    "Stone Golem",
    "Dragon"
};

struct MonsterProfile {
    size_t minATT;     
    size_t rewardEXP; 
    int    baseHP;
    int    currentHP;    
};



MonsterProfile getMonsterProfile(MonsterRank rank);

#endif //_MONSTER_H