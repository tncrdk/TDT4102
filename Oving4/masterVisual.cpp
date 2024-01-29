#include "masterVisual.h"
#include "mastermind.h"
#include "utilities.h"

void playMasterVisual() {
    int guesses = 10;

    while (true) {
        MastermindWindow mwin{900,         20, winW, winH, mastermind::SIZE,
                              "Mastermind"};
        std::string code = utilities::randomizeString(
            mastermind::SIZE, mastermind::LOWER, mastermind::UPPER);
        addGuess(mwin, code, mastermind::LOWER);
        addFeedback(mwin, 0, 0);

        while (true) {
            std::string guess = mwin.getInput(
                mastermind::SIZE, mastermind::LOWER, mastermind::UPPER);

            addGuess(mwin, guess, mastermind::LOWER);

            int correctPositions =
                mastermind::checkCharactersAndPosition(guess, code);
            int correctChars = mastermind::checkChars(guess, code);

            addFeedback(mwin, correctPositions,
                        correctChars - correctPositions);

            if (correctPositions >= mastermind::SIZE) {
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
        mwin.drawGuessesAndFeedbacks();
        mwin.setCodeHidden(false);
        mwin.wait_for_close();
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

void addGuess(MastermindWindow &mwin, const string code,
              const char startLetter) {
    mwin.guesses.push_back(Guess{code, startLetter});
}

void addFeedback(MastermindWindow &mwin, const int correctPosition,
                 const int correctCharacter) {
    mwin.feedbacks.push_back(Feedback{correctPosition, correctCharacter});
}

void MastermindWindow::drawCodeHider() {
    if (code_hidden) {
        draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY,
                       Color::black);
    }
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size,
                                   const string &title)
    : AnimationWindow(x, y, w, h, title),
      guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
      guess{
          {upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
      size(size) {
    add(guess);
    add(guessBtn);
    guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks() {
    std::map<int, Color> colorConverter{
        {1, Color::red},  {2, Color::green},       {3, Color::yellow},
        {4, Color::blue}, {5, Color::blue_violet}, {6, Color::dark_cyan}};

    int y_pos;
    int x_pos;
    for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size());
         guessIndex++) {
        // Implementer funksjonalitet slik at det vises fargede rektangler i
        // grafikkvinduet Tegn gjettet som ligger på plassen guessIndex i
        // vektoren guesses.
        y_pos = (3 + 2 * guessIndex) * padY;
        for (int i = 0; i < size; i++) {
            // Tegn rektangler ved bruk av draw_rectangle(). Bruk:
            // colorConverter.at() for å få riktig farge
            x_pos = (1 + 2 * i) * padX;
            int col_index =
                guesses.at(guessIndex).code.at(i) - mastermind::LOWER + 1;
            Color col = colorConverter.at(col_index);
            draw_rectangle({x_pos, y_pos}, padX, padY, col, Color::black);
        }
    }

    for (int feedbackIndex = 0;
         feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
        // Implementer feedback
        y_pos = (3 + 2 * feedbackIndex + 0.5) * padY;
        for (int i = 0; i < size; i++) {
            // Tegn sirkler ved hjelp av draw_circle().
            x_pos = 9 * padX + radCircle;
            for (int j = 0; j < feedbacks.at(feedbackIndex).correctPosition;
                 ++j) {
                draw_circle({x_pos, y_pos}, radCircle, Color::slate_grey);
                x_pos += 2 * radCircle;
            }
            for (int j = 0; j < feedbacks.at(feedbackIndex).correctCharacter;
                 ++j) {
                draw_circle({x_pos, y_pos}, radCircle, Color::light_grey);
                x_pos += 2 * radCircle;
            }
        }
    }
}

string MastermindWindow::wait_for_guess() {

    while (!button_pressed && !should_close()) {
        drawGuessesAndFeedbacks();
        // Burde tegnes sist siden den skal ligge på toppen
        drawCodeHider();

        next_frame();
    }
    button_pressed = false;

    string newGuess = guess.getText();
    guess.setText("");

    return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper) {
    bool validInput = false;
    string guess;
    while (!validInput && !should_close()) {
        guess.clear();
        string input = wait_for_guess();
        if (input.size() == n) {
            for (unsigned int i = 0; i < n; i++) {
                char ch = input.at(i);
                if (isalpha(ch) && toupper(ch) <= upper &&
                    lower <= toupper(ch)) {
                    guess += toupper(ch);
                } else
                    break;
            }
        }
        if (guess.size() == n) {
            validInput = true;
        } else {
            cout << "Invalid input guess again" << endl;
        }
    }
    return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) { code_hidden = hidden; }
