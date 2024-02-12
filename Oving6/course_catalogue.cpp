#include "course_catalogue.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

namespace CourseCatalogue {
void CourseCatalogue::add_course(std::string course_name,
                                 std::string course_code) {
    this->courses.insert(std::pair{course_code, course_name});
    // this->courses[course_code] = course_name;
}

std::string CourseCatalogue::get_course(std::string course_code) const {
    if (!courses.contains(course_code)) {
        return "";
    }
    return this->courses.at(course_code);
}

void CourseCatalogue::remove_course(std::string course_code) {
    if (!courses.contains(course_code)) {
        std::cout << course_code << " is not in the database.\n";
    }
    this->courses.erase(course_code);
}

void CourseCatalogue::save_courses(std::string filename) const {
    std::ofstream os{std::filesystem::path{filename}};
    std::map<std::string, std::string>::const_iterator it;
    for (it = this->courses.begin(); it != this->courses.end(); ++it) {
        os << it->first << "|" << it->second << "\n";
    }
    os.close();
}

void CourseCatalogue::load_courses(std::string filename) {
    std::string line;
    std::ifstream is{std::filesystem::path{filename}};
    while (std::getline(is, line)) {
        int pos = line.find('|');
        std::string course_code = line.substr(0, pos);
        std::string course_name = line.substr(pos + 1);
        this->add_course(course_name, course_code);
    }
    is.close();
}

std::ostream &operator<<(std::ostream &os, const CourseCatalogue &c) {
    for (std::map<std::string, std::string>::const_iterator it =
             c.courses.begin();
         it != c.courses.end(); ++it) {
        os << "Code: " << it->first << ". Name: " << it->second << "\n";
    }
    return os;
}

void test_course_catalogue() {
    CourseCatalogue c("courses.txt");
    // c.add_course("POOP", "TDT4102");
    // c.add_course("ITGK", "TDT4110");
    // c.add_course("Matematikk 1", "TMT4100");
    std::cout << c << "\n";

    c.remove_course("TMT4100");
    std::cout << c << "\n";

    c.add_course("C++", "TDT4102");
    std::cout << c << "\n";

    std::string s = c.get_course("TDT4102");
    std::cout << s << "\n";
    std::cout << c << "\n";
}
} // namespace CourseCatalogue
