// #ifndef _H_BOSSCHARACTER
// #define _H_BOSSCHARACTER

// #include "character.h"

// class BossCharacter : public Character{

//     private:
//     size_t rank;
//     size_t difficulty;

//     public:

  
//     BossCharacter(string name = "Zakum",size_t rank=100
//         ,size_t yearsPlayed = 30,size_t difficulty = 10)
//     :Character(std::move(name)),rank(rank),difficulty(difficulty){};
//     virtual int getATT() const override{ return 30;}
//     virtual bool isBoss() const override {return true;};
//     // virtual Character* clone() const override{
//     //     return new BossCharacter(*this);
//     // }


//     protected:
//     void toOs(ostream& os) const override {
//         Character::toOs(os);
//         os<<" - BOSS CHARACTER :"<<endl;
//         os << "rank " << rank <<endl
//            << "difficulty " << difficulty<<endl;
//     }

 

// };

// #endif //_H_BOSSCHARACTER

