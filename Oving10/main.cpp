#include "MinesweeperWindow.h"

int main() {
    constexpr int width = 10;
    constexpr int height = 10;
    // constexpr int mines = width * height / 2;
    constexpr int mines = 30;

    Point startPoint{200, 300};
    MinesweeperWindow mw{startPoint.x, startPoint.y, width,
                         height,       mines,        "Minesweeper"};
    mw.wait_for_close();

    return 0;
}
