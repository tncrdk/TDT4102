#include "animal.h"
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

namespace animal {
void test_animal_direct() {
    std::vector<animal::Animal> animals;
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(animal::Animal("Animal" + std::to_string(i), i));
    }
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(animal::Dog("Dog" + std::to_string(i), i));
    }
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(animal::Cat("Cat" + std::to_string(i), i));
    }

    for (int i = 0; i < animals.size(); ++i) {
        std::cout << animals.at(i).to_string() << "\n";
    }

    std::cout << "-----------------------------\n";
    Animal A("A", 21);
    Dog D("D", 21);
    std::cout << A.to_string() << "  |  " << typeid(A).name() << "\n"
              << D.to_string() << "  |  " << typeid(D).name() << "\n";
    std::cout << animals.at(0).to_string() << "  |  "
              << typeid(animals.at(0)).name() << "\n"
              << animals.at(5).to_string() << "  |  "
              << typeid(animals.at(5)).name() << "\n";
    std::cout << "-----------------------------\n";
}

void test_animal_pointer() {
    std::vector<std::unique_ptr<animal::Animal>> animals;
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(
            new animal::Animal("Animal" + std::to_string(i), i));
    }
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(new animal::Dog("Dog" + std::to_string(i), i));
    }
    for (int i = 0; i < 5; ++i) {
        animals.emplace_back(new animal::Cat("Cat" + std::to_string(i), i));
    }

    for (int i = 0; i < animals.size(); ++i) {
        std::cout << animals.at(i).get()->to_string() << "\n";
    }
}
} // namespace animal