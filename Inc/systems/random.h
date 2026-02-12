#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <cstddef>

class Random
{
private:
    Random()
        : engine(std::random_device{}()) {}  // Seed פעם אחת בלבד

public:
    static Random& get()
    {
        static Random instance;  // Meyers Singleton (thread-safe מ־C++11)
        return instance;
    }

    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    std::size_t getRandom(std::size_t range)
    {
        std::uniform_int_distribution<std::size_t> dist(0, range - 1);
        return dist(engine);
    }

private:
    std::mt19937 engine;
};

#endif // RANDOM_H
