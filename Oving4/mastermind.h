#pragma once

#include <string>

namespace mastermind {
// These are constants for the game, and can be evaluated at compile time.
constexpr int SIZE = 4;
constexpr int LETTERS = 6;
constexpr char LOWER = 'A';
constexpr char UPPER = 'A' + LETTERS - 1;

void playMastermind();
int checkChars(std::string guess, std::string code);
int checkCharactersAndPosition(std::string guess, std::string code);
}