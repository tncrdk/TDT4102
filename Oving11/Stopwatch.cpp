#include "Stopwatch.h"
#include <iostream>

void Stopwatch::start() { startTime = std::chrono::steady_clock::now(); }

double Stopwatch::stop() {
    std::chrono::time_point endTime = std::chrono::steady_clock::now();
    long durationInMicroseconds =
        std::chrono::duration_cast<std::chrono::microseconds>(endTime -
                                                              startTime)
            .count();
    double durationInSeconds = double(durationInMicroseconds) / 1000000.0;
    return durationInSeconds;
}

void timeFunc(void (*f)(), int n) {
    Stopwatch watch;
    watch.start();
    for (int i = 0; i < n; ++i) {
        f();
    }
    double time = watch.stop();
    std::cout << "Time: " << time << "sek\n";
}