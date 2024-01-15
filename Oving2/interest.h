#include <vector>

namespace interest {
void printBalance(std::vector<int> balance_vector);
std::vector<int> getBalance(double deposit, int interest, int years);
double calculateBalance(int balance, int interest, int year);
} // namespace interest