#ifndef _JOBFACTORY_H
#define _JOBFACTORY_H
#include <memory>
#include "job.h"
#include "job_types.h"





class JobFactory{

    public:
    static std::unique_ptr<Job> create(eJobType type);

};
#endif //_JOBFACTORY_H