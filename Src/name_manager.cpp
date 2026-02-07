#include "name_manager.h"
#include <fstream>
#include <random>
#include <stdexcept>

using namespace std;

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

    if (pool.empty())
        return "UnknownHero";

    static mt19937 rng{ random_device{}() };
    uniform_int_distribution<size_t> dist(0, pool.size() - 1);

    size_t idx = dist(rng);
    string name = pool[idx];
    pool.erase(pool.begin() + idx); // שלא יחזור

    return name;
}
