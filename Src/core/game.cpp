#include "core/game.h"
#include "core/character.h"
#include "jobs/jobFactory.h"
#include "systems/name_manager.h"
#include <memory>
#include <string>

// ======================================================
// Ctor / Dtor
// ======================================================

Game::Game(string gameName)
    : name(gameName), threadPool(1)
{
    nameManager.loadAll();

    for (size_t i = 0; i<MAX_CHARACTERS; ++i) {
        size_t jobIdx = i%static_cast<size_t>(eJobType::JOB_COUNT);
        string charName = nameManager.getRandomName(eJobType(jobIdx));
        unique_ptr<Job> TheJob = JobFactory::create(eJobType(jobIdx));
        addCharacter(make_unique<Character>(charName,std::move(TheJob)));
    }

    for (size_t i = 0; i < MAX_MISSIONS; ++i) {
        addQuest(make_unique<Task>(
            "Hunt Slime #" + to_string(i + 1),
            MonsterRank::SLIME
        ));
    }
}

Game::~Game()
{
    for (auto& fut : activeFutures) {
        if (fut.valid())
            fut.wait();
    }

}


// ======================================================
// Character Management
// ======================================================

bool Game::canAddCharacter() const
{
    return characters.size() < MAX_CHARACTERS;
}

eAddStatus Game::addCharacter(unique_ptr<Character> c)
{
    if (!c || !canAddCharacter())
        return eAddStatus::FULL;
    characters.push_back(std::move(c));
    return eAddStatus::SUCCESS;
}

// ======================================================
// Quest Management
// ======================================================

bool Game::canAddQuest() const
{
    return questQueue.size() < MAX_MISSIONS;
}

eAddStatus Game::addQuest(unique_ptr<Task> q)
{
    if (!q || !canAddQuest())
        return eAddStatus::FULL;

    questQueue.push_back(std::move(q));
    return eAddStatus::SUCCESS;
}

// ======================================================
// Quest Dispatching
// ======================================================

void Game::dispatchQuests()
{
    while (!questQueue.empty() && !characters.empty()) {

        auto& quest = questQueue.front();
        Character* chosen = nullptr;

        for (size_t i = 0; i < characters.size(); ++i) {
            size_t idx = (nextCharacterIndex + i) % characters.size();
            if (quest->canBeExecutedBy(*characters[idx])) {
                chosen = characters[idx].get();
                nextCharacterIndex = (idx + 1) % characters.size();
                break;
            }
        }

        if (!chosen)
            return;

        auto task = std::move(questQueue.front());
        questQueue.pop_front();

        auto fut = threadPool.submit(
            [task = std::move(task), chosen]() mutable {
                task->execute(*chosen);
            }
        );
        activeFutures.push_back(std::move(fut));
    }
}

void Game::waitForAllQuests()
{
    for (auto& f : activeFutures)
        f.wait();
    activeFutures.clear();
}

// ======================================================
// Debug / Print
// ======================================================

void Game::printStatus() const
{
    cout << "Game: " << name << endl
         << "Characters: " << characters.size() << endl;

    size_t idx = 1;
    for (auto& c : characters)
        cout << "\n" << idx++ << ") " << *c;
}

void Game::printQuests() const
{
    for (auto& q : questQueue)
        q->print();
}

void Game::printCharacters() const
{
    for (auto& c : characters)
        cout << *c;
}
