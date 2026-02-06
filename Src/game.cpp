#include "game.h"

Game::Game(string gameName):
name(gameName),tPool(5)
{
    names=loadNamesFromFile(CHARACTER_NAMES_FILE);
    
    for (size_t i = 1; i <= MAX_CHARACTERS/10; i++) {
        string name = pickRandomName(names);
        addCharacter(make_unique<Thief>(name));
    }

     for (size_t i = 1; i <= MAX_MISSIONS; i++) {
         addMission(make_unique<ThiefTask>());
    }

}

vector<string>Game::loadNamesFromFile(const string& filename)
{
    ifstream file(filename);
    vector<string> result;
    string line;

    if (!file) {
        throw runtime_error("Failed to open names file");
    }

    while (getline(file, line)) {
        if (!line.empty())
            result.push_back(line);
    }
    return result;
}


string Game::pickRandomName(vector<string>& names)
{
    static mt19937 rng{ random_device{}() }; //choose random number
    uniform_int_distribution<size_t> dist(0, names.size() - 1);

    size_t idx = dist(rng);
    string chosen = names[idx];
    names.erase(names.begin() + idx);
    return chosen;
}


bool Game::canAddMoreCharacters() const{
    return (characters.size()<MAX_CHARACTERS);
}

eAddStatus Game::addCharacter(unique_ptr<Character>c){
    if(canAddMoreCharacters() && c)
    {
    characters.push_back(std::move(c));
    return eAddStatus::SUCCESS;
    }
    return eAddStatus::FULL;
}


bool Game::canAddMoreMissions() const{
    return (missionQueue.size()<MAX_MISSIONS);
}

eAddStatus Game::addMission(unique_ptr<Task>t){
    if(!t || !canAddMoreMissions()){
            return eAddStatus::FULL;
    }
    missionQueue.push_back(std::move(t));
    return eAddStatus::SUCCESS;
}


void Game::executeMission()
{
    while (!missionQueue.empty() && !characters.empty()) {

        auto& taskRef = missionQueue.front();

        Character* character = nullptr;

        // (Round Robin + canBeExecutedBy)
        for (size_t i = 0; i < characters.size(); ++i) {
            size_t idx = (nextCharacterIndex + i) % characters.size();
            if (taskRef->canBeExecutedBy(*characters[idx])) {
                character = characters[idx].get();
                nextCharacterIndex = (idx + 1) % characters.size();
                break;
            }
        }

        if (!character) {
            return;
        }
        auto task = std::move(missionQueue.front());
        missionQueue.pop_front();
        auto fut = tPool.submit(
            [task = std::move(task), character]() mutable {
                task->execute(*character);
            }
        );
        activeFutures.push_back(std::move(fut));
    }
}

void Game::printStatus() const{
    cout<<"Game name = "<<name<<endl
    <<"number of people inside: " <<characters.size()<<endl
    <<"members are: "<<endl;
    size_t index=1;
    for(auto& i:characters){
        cout<<"\n"<<index++<<")"<<*i;
    }
}

void Game:: printMissions() const{
   for(auto& msn:missionQueue){
    msn->print();
   }
}

void Game:: printPlayers() const {
    for(auto& player: characters){
        cout<<*player;
    }
}


void Game::waitForMissions(){
    for(auto& f:activeFutures){
        f.wait();
    }
    activeFutures.clear();
}

Game::~Game(){
    for (auto& fut : activeFutures) {
        if (fut.valid())
            fut.wait();
    }
}