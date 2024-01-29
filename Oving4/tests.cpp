#include "utilities.h"
#include <iostream>

namespace tests {
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = utilities::incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment
              << " iterations: " << iterations << " result: " << result
              << std::endl;
}

void testCallByRef() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    utilities::incrementByRefNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment
              << " iterations: " << iterations << " result: " << v0
              << std::endl;
}

void testStudentStruct() {
    utilities::Student stud{"Per", "Fysmat", 10};
    utilities::printStudent(stud);
    bool res = utilities::isInProgram(stud, "Fysmat");
    std::cout << "Res: " << (res ? "True" : "False") << "\n";
}

void testString() {
    // std::string grades = utilities::randomizeString(2, 'A', 'F');
    std::string grades = utilities::readInputToString(2, 'A', 'F');
    std::cout << grades << "\n";
    std::cout << utilities::gradeAverage(grades) << "\n";
}

} // namespace tests