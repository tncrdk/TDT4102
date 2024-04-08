#include "Stopwatch.h"
#include "optimizationTask.h"
#include "optimizationTask_optimized.h"
#include "templates.h"
#include <array>
#include <iostream>
#include <memory>
#include <vector>

constexpr int size = 1000;

void f() { std::unique_ptr<Stopwatch> a = std::make_unique<Stopwatch>(); }
void g() { std::shared_ptr<Stopwatch> a = std::make_shared<Stopwatch>(); }
void stack() { std::array<int, 1000> arr; }
void heap() {
    std::array<int, size> *arr = new std::array<int, size>;
    delete arr;
}
void push_back_bench() {
    std::vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(1);
    }
}
void reserve_bench() {
    int size = 1000000;
    std::vector<int> v;
    v.reserve(size);
    for (int i = 0; i < size; ++i) {
        v.push_back(1);
    }
}
void resize_bench() {
    int size = 1000000;
    std::vector<int> v;
    v.resize(size);
    for (int i = 0; i < size; ++i) {
        v.at(i) = 1;
    }
}
void vector_impl() {
    std::cout << "v:\n";
    std::vector<int> v;
    for (int i = 0; i < 20; ++i) {
        v.push_back(1);
        std::cout << v.size() << "   |   " << v.capacity() << "\n";
    }

    std::cout << "\nw\n";
    std::vector<int> w;
    w.reserve(20);
    for (int i = 0; i < 20; ++i) {
        w.push_back(1);
        std::cout << w.size() << "   |   " << w.capacity() << "\n";
    }

    std::cout << "\na\n";
    std::vector<int> a;
    a.resize(20);
    for (int i = 0; i < 20; ++i) {
        a.push_back(1);
        std::cout << a.size() << "   |   " << a.capacity() << "\n";
    }
}

int main() {
    // Oppg. 1
    // Unique vs shared
    // timeFunc(f, 1000);
    // timeFunc(g, 1000);

    // Stack vs Heap
    // timeFunc(stack, 1000);
    // timeFunc(heap, 1000);

    // Oppg. 2
    // vector_impl();
    // timeFunc(push_back_bench, 1);
    // timeFunc(reserve_bench, 1);
    // timeFunc(resize_bench, 1);

    // Oppg. 3
    // timeFunc(optimizationTask, 1);
    // timeFunc(optimizationTask_optimized, 1);
    // timeFunc(optimizationTask_optimized_array, 1);

    // oppg. 4
    // std::cout << maximum<int>(2, 1) << "\n";
    // std::cout << maximum<double>(5.2, 1.3) << "\n";
    // std::cout << maximum<char>('a', 'e') << "\n";
    // std::vector<int> v{1, 2, 3, 4, 45, 5, 6, 7, 77, 8, 88, 99, 99};
    // std::vector<char> w{'a', 't', 'j', 'q', '5', '5', 'g',
    //                     'b', 's', '8', '8', '9', '9'};
    // shuffle(w);
    // shuffle(v);
    // for (int i = 0; i < w.size(); ++i) {
    //     std::cout << w.at(i) << " ";
    // }
    // std::cout << "\n";
    // for (int i = 0; i < v.size(); ++i) {
    //     std::cout << v.at(i) << " ";
    // }

    // oppg. 5
    MyArray<int, 100> arr;
    arr.fill(23);
    arr.at(3) = 9;
    std::cout << arr.get_size() << "\n";
    std::cout << arr.at(3) << "\n";

    return 0;
}