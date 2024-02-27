#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main() {

    const Point tl{100, 100};
    const string win_label{"Emoji factory"};
    AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    Point centre{xmax / 2, ymax / 2};
    emoji::EmptyFace f(100, centre, 10, Point{20, 20});
    // cout << "Out: " << f.centre.x << "\n";
    cout << centre.x << "\n";
    f.draw(win);

    win.wait_for_close();

    return 0;
}
