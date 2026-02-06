#include "character.h"

void Character::setExp(size_t newExp){
   
   {
    unique_lock<mutex>lock(changeStates_mtx);
    exp+=newExp;
    numOfKILLS++;
    while(exp>=level*10)
    {
        exp-=level*10;
        ++level;
       levelUP_updateSTATS();
    }
   }
}
  
