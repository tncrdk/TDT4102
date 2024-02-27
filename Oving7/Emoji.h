#pragma once
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
namespace emoji {
class Emoji {
  public:
    virtual void draw(AnimationWindow &) = 0;
    virtual ~Emoji(){}; // destruktør
};

class Face : public Emoji {
  public:
    Face(int radius, Point centre) : radius{radius}, centre{centre} {}
    virtual void draw(AnimationWindow &win) override = 0;

  protected:
    int radius;
    Point centre;
};

class EmptyFace : public Face {
  public:
    EmptyFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : Face{radius, centre}, eye_radius{eye_radius}, eye_centre{eye_centre} {
    }
    EmptyFace(int radius, Point centre)
        : EmptyFace{radius, centre, radius / 10,
                    Point{radius / 3, radius / 3}} {}

    void draw(AnimationWindow &win) override;

  protected:
    int eye_radius;
    Point eye_centre;
};

class SmileyFace : public EmptyFace {
  public:
    SmileyFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : EmptyFace(radius, centre, eye_radius, eye_centre) {}
    SmileyFace(int radius, Point centre) : EmptyFace(radius, centre) {}

    void draw(AnimationWindow &win) override;
};

class LaughingFace : public SmileyFace {
  public:
    LaughingFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : SmileyFace(radius, centre, eye_radius, eye_centre) {}
    LaughingFace(int radius, Point centre) : SmileyFace(radius, centre) {}

    void draw(AnimationWindow &win) override;
};

class SadFace : public EmptyFace {
  public:
    SadFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : EmptyFace(radius, centre, eye_radius, eye_centre) {}
    SadFace(int radius, Point centre) : EmptyFace(radius, centre) {}

    void draw(AnimationWindow &win) override;
};

class AngryFace : public EmptyFace {
  public:
    AngryFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : EmptyFace(radius, centre, eye_radius, eye_centre) {}
    AngryFace(int radius, Point centre) : EmptyFace(radius, centre) {}

    void draw(AnimationWindow &win) override;
};

class WinkingFace : public Face {
  public:
    WinkingFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : Face{radius, centre}, eye_radius{eye_radius}, eye_centre{eye_centre} {
    }
    WinkingFace(int radius, Point centre)
        : WinkingFace{radius, centre, radius / 10,
                      Point{radius / 3, radius / 3}} {}

    void draw(AnimationWindow &win) override;

  protected:
    int eye_radius;
    Point eye_centre;
};

class SurprisedFace : public EmptyFace {
  public:
    SurprisedFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : EmptyFace(radius, centre, eye_radius, eye_centre) {}
    SurprisedFace(int radius, Point centre) : EmptyFace(radius, centre) {}

    void draw(AnimationWindow &win) override;
};
} // namespace emoji