#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>

namespace interest {
double calculateBalance(int balance, int interest, int year) {
    return balance * (1 + double(interest) / 100) * std::exp(year);
}

std::vector<int> getBalance(double deposit, int interest, int years) {
    std::vector<int> balance_vector(years + 1);
    for (int i = 0; i < balance_vector.size(); ++i) {
        double balance = calculateBalance(deposit, interest, i);
        balance_vector.at(i) = int(std::round(balance));
    }
    return balance_vector;
}

void printBalance(std::vector<int> balance_vector) {
    std::cout << std::setw(5) << "År" << std::setw(7) << "|" << std::setw(14)
              << "Saldo\n";
    for (int i = 0; i < balance_vector.size(); ++i) {
        std::cout << std::setw(3) << i << std::setw(8) << "|" << std::setw(13)
                  << balance_vector.at(i) << "\n";
    }
}
} // namespace interest