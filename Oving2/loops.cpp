#include <iomanip>
#include <iostream>

namespace loops {
void printSum(int count) {
    int acc = 0;
    std::cout << "Skriv inn " << count << " tall: ";
    for (int i = 0; i < count; ++i) {
        int input = 0;
        std::cin >> input;
        acc += input;
    }
    std::cout << "Sum: " << acc << "\n";
}

void readTilZero() {
    int input;
    int acc = 0;
    while (true) {
        std::cout << "Skriv inn et tall: ";
        std::cin >> input;
        if (input == 0) {
            std::cout << "Summen er " << acc << "\n";
            return;
        }
        acc += input;
    }
}

void convertNokEur() {
    double ratio = 9.75;
    double input = 0;
    while (input <= 0) {
        std::cin >> input;
    }
    double euro = input * ratio;
    std::cout << std::fixed << std::setprecision(2) << "Euro: " << euro << "\n";
}

void multTable() {
    int width = 0;
    int height = 0;
    std::cout << "Skriv inn bredden og høyden: ";
    std::cin >> width >> height;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            std::cout << "   " << j * i;
        }
        std::cout << "\n";
    }
}
} // namespace loops