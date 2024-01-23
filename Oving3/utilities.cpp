#include <random>

namespace utilities {
double get_random_number() {
    std::random_device rd;
    std::default_random_engine generator(rd());
    return generator();
}

double randomWithLimits(double lb, double ub) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(lb, ub);
    return distribution(generator);
}
}