#pragma once
#include <iostream>
#include <utility>

class Dummy {
  public:
    int *num;
    Dummy() { num = new int{0}; }
    Dummy(const Dummy &other) {
        this->num = new int;
        *(this->num) = *(other.num);
    }
    Dummy &operator=(const Dummy &other) {
        // Trengs strengt tatt ikke
        // delete num;
        // num = new int;
        *(this->num) = *other.num;
        return *this;
    }
    ~Dummy() { delete num; }
};

void dummyTest();