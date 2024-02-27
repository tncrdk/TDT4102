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
    // Face(int radius, Point centre) : radius{radius}, centre{centre} {}
    Face(int radius, Point centre) : radius{radius}, centre{centre} {
        // this->radius = radius;
        // this->centre = centre;
        cout << "Face: " << &(this->centre) << "\n";
    }
    virtual void draw(AnimationWindow &win) override = 0;

  protected:
    int radius;
    Point centre;
};

class EmptyFace : public Face {
  public:
    // EmptyFace(int radius, Point centre, int eye_radius, Point eye_centre)
    //     : Face{radius, centre}, eye_radius{eye_radius},
    //     eye_centre{eye_centre} {
    // }
    EmptyFace(int radius, Point centre, int eye_radius, Point eye_centre)
        : Face{radius, centre} {
        cout << "EmptyFace: " << &(this->centre) << "\n";
        this->eye_centre = eye_centre;
        this->eye_radius = eye_radius;
    }
    // EmptyFace(int radius, Point centre)
    //     : EmptyFace{radius, centre, radius / 20,
    //                 Point{radius / 5, radius / 5}} {}

    void draw(AnimationWindow &win) override;

  protected:
    int radius;
    Point centre;
    int eye_radius;
    Point eye_centre;
};
} // namespace emoji