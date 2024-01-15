#include <complex>
#include <iostream>

namespace quad {
double discriminant(double a, double b, double c) { return b * b - 4 * a * c; }
void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);
    double x1 = (-b + std::sqrt(disc)) / (2 * a);
    double x2 = (-b - std::sqrt(disc)) / (2 * a);
    if (disc > 0) {
        std::cout << "x1: " << x1 << "\nx2: " << x2 << "\n";
    } else if (disc < 0) {
        std::cout << "No solution\n";
    } else {
        std::cout << "x: " << x1 << "\n";
    }
}
void solveQuadratic() {
    double a, b, c = 0;
    std::cout << "Skriv inn koeffisientene: ";
    std::cin >> a >> b >> c;
    printRealRoots(a, b, c);
}
} // namespace quad