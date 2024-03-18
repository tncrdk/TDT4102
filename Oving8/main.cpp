#include "dummy.h"
#include "matrix.h"
#include <iostream>

void fillInFibonacciNumbers(int *result, int length) {
    int a = 0;
    int b = 1;
    int temp = 0;

    for (int i = 0; i < length; i++) {
        result[i] = a;
        temp = b;
        b = a + b;
        a = temp;
    }
}

void print_array(int *a, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << a[i] << "\n";
    }
}

void create_fib() {
    int size = 0;
    std::cout << "Hvor mange tall skal genereres? ";
    std::cin >> size;
    int *fib_array = new int[size];

    fillInFibonacciNumbers(fib_array, size);
    print_array(fib_array, size);
    delete[] fib_array;
}

int main() {
    // Oppg. 1
    // const int size = 10;
    // int a[size];
    // fillInFibonacciNumbers(a, size);
    // print_array(a, size);
    // create_fib();

    // Oppg. 2
    matrix::Matrix m(5, 4);
    std::cout << m << "\n";
    matrix::Matrix I(4);
    std::cout << I;
    std::cout << I[3][3] << "\n";

    // Oppg. 3
    // dummyTest();

    // Oppg. 4
    // matrix::Matrix m(5, 4);
    // std::cout << m << "\n";
    // matrix::Matrix I(4);
    // std::cout << I;
    // I = m;
    // std::cout << I << "\n";
    // I[2][3] = 10;
    // std::cout << I << "\n";
    // std::cout << m << "\n";

    // Oppg. 5
    // matrix::Matrix m(4, 4);
    // std::cout << m << "\n";
    // matrix::Matrix I(4);
    // std::cout << I;
    // m += I;
    // std::cout << I << "\n";
    // std::cout << m << "\n";
    // m = I + I + I;
    // std::cout << I << "\n";
    // std::cout << m << "\n";
}