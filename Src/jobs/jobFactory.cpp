#include "jobs/jobFactory.h"
#include "jobs/ArcherJob.h"
#include "jobs/MagicianJob.h"
#include "jobs/WarriorJob.h"
#include "jobs/ThiefJob.h"

std::unique_ptr<Job> JobFactory::create(eJobType type){
        std::unique_ptr<Job> j;
        switch(type){
            case eJobType::THIEF:
            j = std::make_unique<ThiefJob>();
            break;

            case eJobType::MAGICIAN:
            j = std::make_unique<MagicianJob>();
            break;

            case eJobType::WARRIOR:
            j = std::make_unique<WarriorJob>();
            break;

            case eJobType::ARCHER:
            j = std::make_unique<ArcherJob>();
            break;

            default:
            j = std::make_unique<ThiefJob>();
        }
        return j;
}
