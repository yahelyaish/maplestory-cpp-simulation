#include "core/task.h"
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
    if (attacking <= 0)
        return;

    // Simulate fight
    while (currentHP > 0) {
        currentHP -= attacking;
        {
            if(currentHP<=0){
                currentHP=0;
            }
            unique_lock<mutex> lock(g_console_mtx);
            cout<<c.getCharacterName()<<" hit "<<MonsterRankSTR[static_cast<int>(monsterRank)]
            <<"! current TASKID = "<<taskID<<", "<<
            currentHP<<" HP left\n";
        }
       // this_thread::sleep_for(chrono::seconds(1));
    }
    {
        unique_lock<mutex> lock(g_console_mtx);
        cout << c.getCharacterName()
             << " defeated "
             << MonsterRankSTR[static_cast<int>(monsterRank)]
             << endl;
        c.setExp(getRewardEXP());
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
