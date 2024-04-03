#include "MinesweeperWindow.h"

int main() {
    constexpr int width = 3;
    constexpr int height = 3;
    // constexpr int mines = width * height / 2;
    constexpr int mines = 1;

    Point startPoint{200, 300};
    MinesweeperWindow mw{startPoint.x, startPoint.y, width,
                         height,       mines,        "Minesweeper"};
    mw.wait_for_close();

    return 0;
}
