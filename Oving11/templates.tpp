#pragma once
#include <random>

template <typename T> T maximum(T lhs, T rhs) {
    if (lhs >= rhs) {
        return lhs;
    }
    return rhs;
}

template <typename T> void shuffle(std::vector<T> &v) {
    std::random_device seed;
    std::default_random_engine engine(seed());
    std::uniform_int_distribution<int> dist(0, v.size() - 1);
    int rnd;
    for (int i = 0; i < v.size(); ++i) {
        rnd = dist(engine);
        std::swap(v.at(i), v.at(rnd));
    }
}