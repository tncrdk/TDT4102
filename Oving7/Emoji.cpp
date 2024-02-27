#include "Emoji.h"

namespace emoji {
void Face::draw(AnimationWindow &win) {
    win.draw_circle(this->centre, this->radius, Color::yellow);
}

void EmptyFace::draw(AnimationWindow &win) {
    Face::draw(win);
    int x = this->eye_centre.x;
    int y = this->eye_centre.y;
    Point left_eye{this->centre.x - x, this->centre.y - y};
    Point right_eye{this->centre.x + x, this->centre.y - y};
    cout << left_eye.x;
    win.draw_circle(left_eye, this->eye_radius, Color::red);
    win.draw_circle(right_eye, this->eye_radius, Color::red);
}
} // namespace emoji