#include <iostream>

namespace menu {
int add(int a, int b) { return a + b; }

void inputIntegersAndPrintProduct() {
    int x = 0;
    int y = 0;

    std::cout << "Skriv inn et heltall: ";
    std::cin >> x;
    std::cin >> y;

    int product = x * y;
    std::cout << x << " * " << y << " = " << product << std::endl;
}

void inputAndPrintInteger() {
    int a = 0;
    std::cout << "Skriv inn et tall: ";
    std::cin >> a;
    std::cout << "Du skrev: " << a << "\n";
}

int inputInteger() {
    int a = 0;
    std::cout << "Skriv inn et tall: ";
    std::cin >> a;
    return a;
}

double inputDouble() {
    double a = 0;
    std::cout << "Skriv inn et tall: ";
    std::cin >> a;
    return a;
}

bool isOdd(int value) {
    if (value % 2 == 0) {
        return false;
    }
    return true;
}
} // namespace menu