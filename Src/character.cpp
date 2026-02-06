#include "character.h"

void Character::setExp(size_t newExp){
   
   {
    unique_lock<mutex>lock(changeStates_mtx);
    exp+=newExp;
    numOfTask++;
    while(exp>=level*10)
    {
        exp-=level*10;
        ++level;
     //   baseAttack+=10;
        baseDefence+=10;
      // levelUP_updateSTATS();
    }
   }
}
  
