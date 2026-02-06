#ifndef _BEGINNER_CHARACTER
#define _BEGINNER_CHARACTER
#include "character.h"

class Beginner: public Character{
    
    private:
    size_t attack;
    size_t defense;

    protected:
    virtual string getJobName() const override{
        return "Beginner";
    }
    public:
    Beginner():Character("Beginner"),attack(10),defense(10){};
    Beginner(string name):Character(std::move(name)),
    attack(10),defense(10){}; 

    size_t getATT() const override{return attack;};
    size_t getDEF() const override {return defense;};

    protected:
     virtual void toOs(ostream& os) const override{
        Character::toOs(os);
    }
};

#endif //_BEGINNER_CHARACTER