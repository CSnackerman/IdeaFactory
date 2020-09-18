#ifndef TIMING_H
#define TIMING_H

#include <chrono>

using namespace std::chrono;

class Timing {
private:
    system_clock sysClock;

    steady_clock steadyClock;
    steady_clock::time_point scStart, scEnd;
    steady_clock::duration scDuration;

    high_resolution_clock hiResClock;
    high_resolution_clock::time_point hrcStart, hrcEnd;
    high_resolution_clock::duration hrcDuration;


public:
};

#endif