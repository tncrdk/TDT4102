#pragma once
#include <string>
#include <vector>

namespace utilities {
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByRefNumTimes(int &startValue, int increment, int numTimes);
void swap(int &num1, int &num2);

struct Student {
    std::string name;
    std::string studyProgram;
    int age;
};

void printStudent(Student stud);
bool isInProgram(Student stud, std::string studyProgram);
std::string randomizeString(int nSymbols, char lower, char upper);
std::string readInputToString(int n, char lower, char upper);
int countChar(std::string input, char s);
double gradeAverage(std::string grades);
double average(std::vector<int> gradeCount);
}