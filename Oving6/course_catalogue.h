#pragma once
#include <istream>
#include <map>
#include <ostream>
#include <string>

namespace CourseCatalogue {
class CourseCatalogue {
  public:
    CourseCatalogue(std::map<std::string, std::string> m, std::string filename)
        : courses(m), filename(filename) {}
    CourseCatalogue(std::string filename) : filename(filename) {
        this->load_courses(filename);
    }
    CourseCatalogue() {}
    ~CourseCatalogue() { this->save_courses(this->filename); }

    void add_course(std::string course_name, std::string course_code);
    void remove_course(std::string course_code);
    std::string get_course(std::string course_code) const;
    void save_courses(std::string filename) const;
    void load_courses(std::string filename);

    friend std::ostream &operator<<(std::ostream &os, const CourseCatalogue &c);
    friend std::istream &operator>>(std::istream &os, const CourseCatalogue &c);

  private:
    std::map<std::string, std::string> courses;
    std::string filename;
};

void test_course_catalogue();
} // namespace CourseCatalogue