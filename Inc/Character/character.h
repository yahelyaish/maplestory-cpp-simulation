#ifndef _H_CHARACTER
#define _H_CHARACTER

#include "iostream"
using namespace std;

enum class eStatus{
    SUCCESS = 0 ,
    INVALID_YEAR
};

enum class eJobType{
    BEGINNER,
    THEIF,
    MAGICIAN,
    JOB_COUNT
};

extern const char* strStatus[];

class Character {
protected:
    string name;
    size_t level=1;
    size_t exp=0;
    size_t baseAttack=1;
    size_t baseDefence=1;
    
virtual void toOs(ostream& os) const {
        os  <<"\nName: "<<name<<"\n"
            <<"Job: "<<getJobName()<<"\n"
            <<"Level: "<<getLEVEL()<<"\n"
            <<"EXP: "<<getEXP()<<"\n"
            <<"ATT: "<<getATT()<<"\n"
            <<"DEF: "<<getDEF()<<endl;
     }
public:

    Character(string name="unKnown Character"):name(std::move(name)){}

    virtual ~Character() = default;

    virtual size_t getATT() const = 0;
    virtual size_t getDEF() const= 0;
    virtual string getJobName() const = 0;

    inline string getCharacterName() const{return name.c_str();} ;
    inline size_t getEXP() const{return exp;};
    inline size_t getLEVEL() const{return level;};
    inline void setExp(size_t newExp){exp+=newExp;};


    friend std::ostream& operator<<(ostream& os, const Character& ch) {
        ch.toOs(os);
        return os;
    }
};

#endif //_H_CHARACTER