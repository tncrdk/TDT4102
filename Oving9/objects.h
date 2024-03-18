#pragma once
#include <iostream>
#include <memory>
#include <string>

class Car {
  public:
    Car(int free_seats) : free_seats{free_seats} {}
    bool has_free_seats() const;
    void reserve_seat();

  private:
    int free_seats;
};

class Person {
  public:
    Person(std::string name, std::string email,
           std::unique_ptr<Car> car = nullptr)
        : name{name}, email{email}, car{std::move(car)} {}
    std::string get_name() const { return this->name; }
    std::string get_email() const { return this->email; }
    void set_email(std::string value) { this->email = value; }
    bool has_available_seats() const;
    friend std::ostream &operator<<(std::ostream &os, const Person &p);

  private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;
};
