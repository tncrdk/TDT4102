#include "objects.h"

bool Car::has_free_seats() const { return free_seats > 0; }
void Car::reserve_seat() { --free_seats; }

bool Person::has_available_seats() const {
    if (car != nullptr) {
        return car->has_free_seats();
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "Name: " << p.get_name() << "\nEmail: " << p.get_email()
       << "\nHas available seats: "
       << (p.has_available_seats() ? "true" : "false") << "\n";
    return os;
}