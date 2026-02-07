#ifndef __NAME_MANAGER_H
#define __NAME_MANAGER_H

#include <string>
#include <vector>
#include "configurations.h"

using namespace std;

class NameManager {
private:
    vector<vector<string>> namePools; // index = eJobType

public:
    NameManager()
        : namePools(static_cast<size_t>(eJobType::JOB_COUNT)) {}

    void loadAll();
    string getRandomName(eJobType job);
};

#endif // __NAME_MANAGER_H
