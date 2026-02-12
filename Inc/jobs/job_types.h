#ifndef _JOB_TYPES_
#define _JOB_TYPES_
#include <string>


enum class eJobType {
    THIEF = 0,
    MAGICIAN,
    ARCHER,
    WARRIOR,
    JOB_COUNT
};

const std::string JobSTR[]={"THIEF","MAGICIAN","ARCHER","WARRIOR"};


#endif //_JOB_TYPES