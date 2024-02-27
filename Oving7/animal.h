#include <string>

namespace animal {
class Animal {
  public:
    Animal(std::string name, int age) : name{name}, age{age} {}
    virtual ~Animal() {}

    virtual std::string to_string() {
        return "Animal: " + this->name + ", " + std::to_string(this->age);
    }
    // virtual std::string to_string() = 0;

  protected:
    std::string name;
    int age;

  private:
};

class Dog : public Animal {
  public:
    Dog(std::string name, int age) : Animal(name, age) {}

    std::string to_string() override {
        return "Dog: " + this->name + ", " + std::to_string(this->age);
    }
};

class Cat : public Animal {
  public:
    Cat(std::string name, int age) : Animal(name, age) {}

    std::string to_string() override {
        return "Cat: " + this->name + ", " + std::to_string(this->age);
    }
};

void test_animal_direct();
void test_animal_pointer();
} // namespace animal