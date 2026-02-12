#ifndef _TIMER_H
#define _TIMER_H
#include <iostream>
#include <chrono>
using namespace std;
struct Timer{

    chrono::time_point<chrono::high_resolution_clock> start,end;
    chrono::duration<float> duration;

    Timer(){
        start = chrono::high_resolution_clock::now();
    }

    ~Timer(){
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    float ms = duration.count()*1000.0f;
    cout<<"game took: " << ms << "ms \n";
    }

};


#endif //_TIMER_H