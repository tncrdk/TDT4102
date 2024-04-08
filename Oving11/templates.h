#pragma once
#include <exception>
#include <iostream>
#include <vector>

template <typename T> T maximum(T lhs, T rhs);
template <typename T> void shuffle(std::vector<T> &v);

template <typename T, size_t N> class MyArray {
  public:
    size_t get_size() const { return N; }
    T &at(int index) {
        if (index < N && index >= 0) {
            return this->elements[index];
        }
        throw std::invalid_argument("Index must be less than the length of the "
                                    "vector and greater than one.");
    }
    void fill(T value) {
        for (int i = 0; i < N; ++i) {
            elements[i] = value;
        }
    }

  private:
    T elements[N];
};

#include "templates.tpp"