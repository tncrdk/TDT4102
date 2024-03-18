#include "meeting.h"
#include "meetingWindow.h"
#include "objects.h"
#include <iostream>

int main() {
    // std::unique_ptr<Car> car_ptr = std::make_unique<Car>(3);
    // Person p("Foo", "Bar", std::move(car_ptr));
    // std::cout << p << "\n";
    // Person p1("Foo", "Bar", std::make_unique<Car>(0));
    // std::cout << p1 << "\n";
    // Meeting m(0, 1200, 1300, Campus::Trondheim, "Tull og vås",
    //           std::shared_ptr<Person>(
    //               new Person("Per", "Nord", std::make_unique<Car>(2))));
    // m.add_participant(std::shared_ptr<Person>(
    //     new Person("Foo", "Bar", std::make_unique<Car>(0))));

    // Meeting m1(0, 1300, 1400, Campus::Trondheim, "Noe annet tull og vås",
    //            std::shared_ptr<Person>(
    //                new Person("Espen", "Nord", std::make_unique<Car>(2))));
    // m1.add_participant(std::shared_ptr<Person>(
    //     new Person("Baz", "Bar", std::make_unique<Car>(0))));

    // std::vector<std::shared_ptr<Person>> d = m.find_CoDriver(m1);

    // std::cout << m;
    // for (int i = 0; i < d.size(); ++i) {
    //     std::cout << *d.at(i);
    // }
    MeetingWindow m(100, 100, 500, 500, "Hallo");
    m.wait_for_close();
    m.print();
    return 0;
}