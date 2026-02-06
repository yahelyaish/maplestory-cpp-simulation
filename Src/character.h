#ifndef _H_CHARACTER
#define _H_CHARACTER

#include "iostream"
using namespace std;
#include <mutex>
enum class eStatus{
    SUCCESS = 0 ,
    INVALID_YEAR
};

enum class eJobType{
    THIEF,
    MAGICIAN,
    ARCHER,
    WARRIOR,
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
    size_t numOfKILLS=0;
    mutex changeStates_mtx;


virtual void toOs(ostream& os) const {
        os  <<"\nName: "<<name<<"\n"
            <<"Job: "<<getJobName()<<"\n"
            <<"Level: "<<getLEVEL()<<"\n"
            <<"EXP: "<<getEXP()<<"\n"
            <<"ATT: "<<getATT()<<"\n"
            <<"DEF: "<<getDEF()<<endl
            <<"number of KILLS: "<< numOfKILLS <<endl;
     }
public:

    Character(string name="unKnown Character"):name(std::move(name)){}
    Character(string name,size_t att,size_t def)
    :name(std::move(name)),baseAttack(att),baseDefence(def){}
    virtual ~Character() = default;

    virtual size_t getATT() const = 0;
    virtual size_t getDEF() const= 0;
    virtual string getJobName() const = 0;

    inline string getCharacterName() const{return name.c_str();} ;
    inline size_t getEXP() const{return exp;};
    inline size_t getLEVEL() const{return level;};
    void setExp(size_t newExp);
    virtual void levelUP_updateSTATS() =0;
    friend std::ostream& operator<<(ostream& os, const Character& ch) {
        ch.toOs(os);
        return os;
    }
};

#endif //_H_CHARACTER