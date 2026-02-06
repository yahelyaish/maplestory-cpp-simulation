#ifndef _THEIF_CHARACTER
#define _THEIF_CHARACTER
#include "character.h"


class Thief: public Character{


    public:
    Thief():Character("Thief",20,20){}
    Thief(const string& str):Character(std::move(str),20,20){}
    virtual string getJobName() const override{
    return "Theif";
    }

    protected:
    size_t getATT() const override{ return baseAttack;};
    size_t getDEF() const override{ return baseDefence;};
    virtual void levelUP_updateSTATS() override  {
        baseAttack+=10;
        baseDefence+=10;
    }
    virtual void toOs(ostream& os) const override{
        Character::toOs(os);
    }
};

#endif //_THEIF_CHARACTER