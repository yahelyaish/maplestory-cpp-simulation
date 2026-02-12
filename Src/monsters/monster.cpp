#include "monsters/monsters.h"



MonsterProfile getMonsterProfile(MonsterRank rank)
{
    if (rank == MonsterRank::SLIME)
        return {10,  8,   60,60};
    else if (rank == MonsterRank::WILD_BOAR)
        return {18, 18,  180,180};
    else if (rank == MonsterRank::STONE_GOLEM)
        return {26, 40,  450,450};
    else if (rank == MonsterRank::DRAGON)
        return {40,120, 1200,1200};

    return {999999, 0, 0,0};
}
