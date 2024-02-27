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

    // std::vector<emoji::Emoji *> emojis{
    //     new emoji::EmptyFace(50, Point{100, 100}),
    //     new emoji::SmileyFace(50, Point{200, 100}),
    //     new emoji::LaughingFace(50, Point{300, 100}),
    // };
    // for (std::vector<emoji::Emoji *>::iterator f = emojis.begin();
    //      f != emojis.end(); ++f) {
    //     (*f)->draw(win);
    // }

    vector<unique_ptr<emoji::Emoji>> emojis;
    emojis.emplace_back(new emoji::SmileyFace(50, Point{100, 100}));
    emojis.emplace_back(new emoji::LaughingFace(50, Point{200, 100}));
    emojis.emplace_back(new emoji::AngryFace(50, Point{300, 100}));
    emojis.emplace_back(new emoji::SadFace(50, Point{400, 100}));
    emojis.emplace_back(new emoji::SurprisedFace(50, Point{500, 100}));

    for (std::vector<unique_ptr<emoji::Emoji>>::iterator f = emojis.begin();
         f != emojis.end(); ++f) {
        (*f)->draw(win);
    }

    win.wait_for_close();

    return 0;
}
