#ifndef _STATS_H
#define _STATS_H
#include <iostream>

struct Stats {
    size_t attack;
    size_t defense;
    int    hp;
    int    mp;

    Stats& operator+=(const Stats& other){
        attack+=other.attack;
        defense+=other.defense;
        hp+=other.hp;
        mp+=other.mp;
        return *this;
    }

friend std::ostream& operator<<(std::ostream& os, const Stats& s) {
    os << "ATT: " << s.attack
       << "  DEF: " << s.defense
       << "  HP: "  << s.hp
       << "  MP: "  << s.mp;
    return os;
}
};

#endif //_STATS_H