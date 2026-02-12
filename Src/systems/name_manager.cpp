#include "systems/name_manager.h"
#include <fstream>
#include <stdexcept>
#include "systems/random.h"
#include <iostream>


static vector<string> loadFile(const string& filename)
{
    ifstream file(filename);
    if (!file)
        throw runtime_error("Failed to open " + filename);

    vector<string> names;
    string line;

    while (getline(file, line)) {
        if (!line.empty())
            names.push_back(line);
    }
    return names;
}

void NameManager::loadAll()
{
    for (int i = 0; i < static_cast<int>(eJobType::JOB_COUNT); ++i) {
        eJobType job = static_cast<eJobType>(i);
        namePools[i] = loadFile(getFileNameJobs(job));
    }
}

string NameManager::getRandomName(eJobType job)
{
    auto& pool = namePools[static_cast<int>(job)];
    cout<<"succeeded get name value\n";
    auto& rnd = Random::get();
    if (pool.empty())
        return "UnknownHero";
   
    size_t idx =  rnd.getRandom(pool.size());
    string name = pool[idx];
    pool.erase(pool.begin() + idx); 

    return name;
}

string  NameManager::getFileNameJobs(eJobType job)
{
    return JOB_NAME_FILES[static_cast<int>(job)];
}
