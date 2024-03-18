#include "meetingWindow.h"

void MeetingWindow::new_person() {
    std::string name = person_name.getText();
    std::string email = person_email.getText();
    std::unique_ptr<Car> car_ptr;
    try {
        int car_seats = std::stoi(person_seats.getText());
        if (car_seats < 0) {
            return;
        }
        car_ptr = std::make_unique<Car>(car_seats);
        std::cout << "Under car_ptr\n";
        if (car_seats > 0) {
            car_ptr->reserve_seat();
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return;
    }
    if (name == "Name" || email == "Email") {
        return;
    }
    person_name.setText("Name");
    person_email.setText("Email");
    person_seats.setText("Car seats");
    people.emplace_back(
        std::shared_ptr<Person>(new Person(name, email, std::move(car_ptr))));
}