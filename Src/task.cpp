#include "task.h"
#include <chrono>
#include <thread>
// ======================================================
// Helpers
// ======================================================

size_t Task::getRewardEXP() const
{
    return getMonsterProfile(monsterRank).rewardEXP;
}

int Task::getMonsterHP() const
{
    return getMonsterProfile(monsterRank).baseHP;
}

// ======================================================
// Gameplay
// ======================================================

bool Task::canBeExecutedBy(const Character& c) const
{
    return c.getATT() >= getMonsterProfile(monsterRank).minATT;
}

void Task::execute(Character& c)
{
    int attacking = static_cast<int>(c.getATT());
    int monsterHP = getMonsterHP();

    if (attacking <= 0)
        return;

    // Simulate fight
    while (monsterHP > 0) {
        monsterHP -= attacking;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    c.setExp(getRewardEXP());

    {
        unique_lock<mutex> lock(g_console_mtx);
        cout << c.getCharacterName()
             << " defeated "
             << MonsterRankSTR[static_cast<int>(monsterRank)]
             << " (Quest ID: " << getTaskID() << ")"
             << endl;
    }
}

// ======================================================
// Debug
// ======================================================

void Task::print() const
{
    auto profile = getMonsterProfile(monsterRank);

    cout << "\nQuest ID: " << taskID
         << "\nName: " << name
         << "\nMonster: " << MonsterRankSTR[static_cast<int>(monsterRank)]
         << "\nRequired ATT: " << profile.minATT
         << "\nMonster HP: " << profile.baseHP
         << "\nReward EXP: " << profile.rewardEXP
         << endl;
}
