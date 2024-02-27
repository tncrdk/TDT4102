#include "animal.h"
#include <iostream>

int main() {
    // animal::Animal a("A", 10);
    // animal::Dog d("D", 21);
    // animal::Cat c("C", 4);

    // std::cout << a.to_string() << "\n";
    // std::cout << d.to_string() << "\n";
    // std::cout << c.to_string() << "\n";
    std::cout << "--------------------\n";
    animal::test_animal_direct();
    std::cout << "--------------------\n";
    animal::test_animal_pointer();
}