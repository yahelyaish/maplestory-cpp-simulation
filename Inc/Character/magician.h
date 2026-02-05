#ifndef _MAGICIAN_CHARACTER
#define _MAGICIAN_CHARACTER
#include "character.h"

class Magician: public Character{
    private:
    size_t attack;
    size_t defense;

    protected:
    virtual string getJobName() const override{
        return "Magician";
    }

    
    public:
    Magician():Character("Magician"),attack(15),defense(15){};  
    Magician(string name):Character(std::move(name))
    ,attack(15),defense(15){}; 

    size_t getATT() const override{return attack;};
    size_t getDEF() const override {return defense;};
    protected:
     virtual void toOs(ostream& os) const override{
        Character::toOs(os);
    }
};

#endif //_MAGICIAN_CHARACTER