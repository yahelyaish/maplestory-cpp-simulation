#include "game.h"
#include "ThreadPool.h"

Game::Game(string gameName):
name(gameName),tPool(3)
{
    for (size_t i = 1; i <= MAX_CHARACTERS / 3; i++) {
        addCharacter(make_unique<Theif>(to_string(i)));
        addMission(make_unique<TheifTask>());
    }

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
    while (!missionQueue.empty()) {
        auto& taskRef = missionQueue.front();
        if (!characters.empty() &&
            taskRef->canBeExecutedBy(*characters.front())) {

            auto task = std::move(missionQueue.front());
            missionQueue.pop_front();
            
            Character* character = characters.front().get();   
            tPool.submit(  [task=std::move(task),character]
            ()mutable 
            {task->execute(*character); });
        }else{
            break;
        }
    }
}

void Game::printStatus() const{
    cout<<"Game name = "<<name<<endl
    <<"number of people inside: " <<characters.size()<<endl
    <<"members are: "<<endl;
    size_t index=1;
    for(auto& i:characters){
        cout<<endl;
        cout<<index++<<")"<<*i;
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