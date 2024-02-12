#pragma once
#include <AnimationWindow.h>
#include <istream>
#include <map>

void bouncing_ball();

struct Config {
    int up_color;
    int down_color;
    int vel_abs;
};

std::istream &operator>>(std::istream &is, Config &cfg);