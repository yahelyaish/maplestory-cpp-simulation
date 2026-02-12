#ifndef _ALOCATION_MATRICS_H
#define _ALOCATION_MATRICS_H
#include <cstddef>

class AllocationMetrics {
private:
    AllocationMetrics() = default;

public:
    static AllocationMetrics& get() {
        static AllocationMetrics instance;
        return instance;
    }

    AllocationMetrics(const AllocationMetrics&) = delete;
    AllocationMetrics& operator=(const AllocationMetrics&) = delete;

    void onAlloc(size_t bytes) {
        totalAllocations+=bytes;
        currentAllocations+=bytes;
    }

    void onFree(size_t bytes) {
        totalFreed+=bytes;
        currentAllocations-=bytes;
    }

    size_t total() const { return totalAllocations/8; }
    size_t freed() const { return totalFreed/8; }
    size_t current() const { return currentAllocations/8; }


private:
    size_t totalAllocations  = 0;
    size_t totalFreed        = 0;
    size_t currentAllocations = 0;
};



#endif //_ALOCATION_MATRICS_H