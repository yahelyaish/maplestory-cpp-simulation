#ifndef __NAME_MANAGER_H
#define __NAME_MANAGER_H

#include <string>
#include <vector>
#include "jobs/job_types.h"
using namespace std;

constexpr const char* JOB_NAME_FILES[] = {
    "assets/names/thief.txt",
    "assets/names/magician.txt",
    "assets/names/archer.txt",
    "assets/names/warrior.txt"
};

class NameManager {
private:
    vector<vector<string>> namePools; // index = eJobType

public:
    NameManager()
        : namePools(static_cast<size_t>(eJobType::JOB_COUNT)) {}

    void loadAll();
    string getFileNameJobs(eJobType job);
    string getRandomName(eJobType job);
};

#endif // __NAME_MANAGER_H
