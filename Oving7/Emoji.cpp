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
    win.draw_circle(left_eye, this->eye_radius, Color::black);
    win.draw_circle(right_eye, this->eye_radius, Color::black);
}

void SmileyFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(centre, radius * 0.8, radius * 0.8, 180, 360, Color::black);
}

void LaughingFace::draw(AnimationWindow &win) {
    SmileyFace::draw(win);
    win.draw_arc(centre, radius * 0.8, radius * 0.5, 180, 360, Color::black);
}

void SadFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    Point arc_centre{centre.x, centre.y + radius * 0.5};
    win.draw_arc(arc_centre, radius * 0.5, radius * 0.5, 0, 180, Color::black);
}

void AngryFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    Point arc_centre{centre.x, centre.y + radius * 0.5};
    win.draw_arc(arc_centre, radius * 0.5, radius * 0.1, 0, 180, Color::black);

    int x = this->eye_centre.x;
    int y = this->eye_centre.y;
    Point left_eye{this->centre.x - x, this->centre.y - y};
    Point right_eye{this->centre.x + x, this->centre.y - y};

    Point brows_start{-radius * 0.2, radius * 0.2 + eye_radius * 1.2};
    Point brows_end{radius * 0.2, 0 + eye_radius * 1.2};

    win.draw_line(Point{left_eye.x + brows_start.x, left_eye.y - brows_start.y},
                  Point{left_eye.x + brows_end.x, left_eye.y - brows_end.y},
                  Color::black);
    win.draw_line(
        Point{right_eye.x - brows_start.x, right_eye.y - brows_start.y},
        Point{right_eye.x - brows_end.x, right_eye.y - brows_end.y},
        Color::black);
}

void WinkingFace::draw(AnimationWindow &win) {
    Face::draw(win);
    int x = this->eye_centre.x;
    int y = this->eye_centre.y;
    Point left_eye{this->centre.x - x, this->centre.y - y};
    Point right_eye{this->centre.x + x, this->centre.y - y};
    win.draw_circle(left_eye, this->eye_radius, Color::black);
    win.draw_arc(right_eye, this->eye_radius * 1.3, this->eye_radius * 1.3, 0,
                 180, Color::black);
    // win.draw_arc(centre, radius * 0.8, radius * 0.8, 180, 360, Color::black);
    win.draw_arc(centre, radius * 0.8, radius * 0.5, 180, 360, Color::black);
}

void SurprisedFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    Point arc_centre{centre.x, centre.y + radius * 0.5};
    win.draw_circle(arc_centre, radius * 0.3, Color::black);
}
} // namespace emoji