#ifndef _THEIF_CHARACTER
#define _THEIF_CHARACTER
#include "character.h"


class Theif: public Character{


    public:

    Theif():Character("Theif"){}
    Theif(string name):Character(std::move(name)){}; 

    virtual string getJobName() const override{
    return "Theif";
    }

    protected:
    size_t getATT() const override{ return baseAttack*20;};
    size_t getDEF() const override{ return baseDefence*20;};
    virtual void toOs(ostream& os) const override{
        Character::toOs(os);
    }
};

#endif //_THEIF_CHARACTER