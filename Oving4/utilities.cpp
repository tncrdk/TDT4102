#include "utilities.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace utilities {
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByRefNumTimes(int &startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Oppg. 2

void printStudent(Student stud) {
    std::cout << "Navn: " << stud.name << "\nAge: " << stud.age
              << "\nStudyProgram: " << stud.studyProgram << "\n";
}

bool isInProgram(Student stud, std::string studyProgram) {
    return stud.studyProgram == studyProgram;
}

// Oppg. 3

std::string randomizeString(int nSymbols, char lower, char upper) {
    std::random_device seed;
    std::default_random_engine generator(seed());
    std::uniform_int_distribution<int> distribution(lower, upper);
    std::string a = "";
    int i = 0;
    for (;;) {
        if (i >= nSymbols) {
            break;
        }
        int randomInt = distribution(generator);
        char randomChar = static_cast<char>(randomInt);
        a.push_back(randomChar);
        ++i;
    }
    return a;
}

std::string readInputToString(int n, char lower, char upper) {
    char lower_limit = std::toupper(lower);
    char upper_limit = std::toupper(upper);
    std::string res = "";
    for (int i = 0; i < n; ++i) {
        char input;
        while (true) {
            std::cout << "Skriv inn en karakter mellom " << lower_limit << "-"
                      << upper_limit << ": ";
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (!std::isalnum(input)) {
                std::cout << "Inputen var ikke gyldig. Prøv på nytt.\n";
                continue;
            }
            input = std::toupper(input);
            if (input < lower_limit || input > upper_limit) {
                std::cout << "Inputen var ikke gyldig. Prøv på nytt.\n";
                continue;
            }
            break;
        }
        res.push_back(input);
    }
    return res;
}

int countChar(std::string input, char s) {
    int counter = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input.at(i) == s) {
            ++counter;
        }
    }
    return counter;
}

double average(std::vector<int> gradeCount) {
    double acc = 0;
    int grades = 0;
    for (int i = 0; i < gradeCount.size(); ++i) {
        int weight = gradeCount.size() - i;
        grades += gradeCount.at(i);
        acc += weight * gradeCount.at(i);
    }
    return acc / grades;
}

double gradeAverage(std::string grades) {
    std::string possibleGrades = "ABCDEF";
    std::vector<int> gradeCount(possibleGrades.size(), 0);
    for (int i = 0; i < possibleGrades.size(); ++i) {
        gradeCount.at(i) = countChar(grades, possibleGrades.at(i));
    }
    return average(gradeCount);
}
} // namespace utilities