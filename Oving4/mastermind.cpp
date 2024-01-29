#include "mastermind.h"
#include "utilities.h"
#include <iostream>
#include <string>

namespace mastermind {
void playMastermind() {
    int guesses = 10;

    while (true) {
        std::string code = utilities::randomizeString(SIZE, LOWER, UPPER);
        // For debugging
        // std::cout << code << "\n";
        while (true) {
            std::string guess =
                utilities::readInputToString(SIZE, LOWER, UPPER);
            int correctPositions = checkCharactersAndPosition(guess, code);
            int correctChars = checkChars(guess, code);

            if (correctPositions >= SIZE) {
                std::cout << "Gratulerer! Du vant!\n";
                break;
            }

            std::cout << "Riktige bokstaver: " << correctChars
                      << "\nRiktige bokstaver på riktig posisjon: "
                      << correctPositions << "\n";
            --guesses;

            if (guesses <= 0) {
                std::cout << "Du tapte.\n";
                break;
            }
        }

        char input;
        std::cout << "Vil du spille igjen? [Y/N]: ";
        std::cin >> input;
        input = std::toupper(input);
        if (input == 'Y') {
            continue;
        } else {
            std::cout << "Hade!\n";
            return;
        }
    }
}

int checkCharactersAndPosition(std::string guess, std::string code) {
    int counter = 0;
    for (int i = 0; i < code.size(); ++i) {
        if (guess.at(i) == code.at(i)) {
            ++counter;
        }
    }
    return counter;
}

int checkChars(std::string guess, std::string code) {
    int counter = 0;
    for (char i = LOWER; i <= UPPER; ++i) {
        int code_n = utilities::countChar(code, i);
        int guess_n = utilities::countChar(guess, i);
        int diff = code_n - guess_n;
        if (diff >= 1) {
            counter += guess_n;
        } else {
            counter += code_n;
        }
    }
    return counter;
}
} // namespace mastermind