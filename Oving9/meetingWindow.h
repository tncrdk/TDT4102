#pragma once
#include "AnimationWindow.h"
#include "objects.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include <string>

class MeetingWindow : public TDT4102::AnimationWindow {
  public:
    MeetingWindow(int x, int y, int w, int h, const std::string &title)
        : AnimationWindow(x, y, w, h, title),
          quit_btn{
              TDT4102::Button{TDT4102::Point{w - btnW, 0}, btnW, btnH, "Quit"}},
          add_person_btn{
              TDT4102::Button{TDT4102::Point{pad, fieldH * 3 + pad * 3}, btnW,
                              btnH, "Add person"}},
          person_name{TDT4102::TextInput(TDT4102::Point{pad, 0}, fieldW, fieldH,
                                         "Name")},
          person_email{TDT4102::TextInput(TDT4102::Point{pad, fieldH + pad},
                                          fieldW, fieldH, "Email")},
          person_seats{
              TDT4102::TextInput(TDT4102::Point{pad, fieldH * 2 + pad * 2},
                                 fieldW, fieldH, "Car seats")} {
        this->add(this->quit_btn);
        this->add(this->person_name);
        this->add(this->person_email);
        this->add(this->person_seats);
        this->add(this->add_person_btn);
        this->quit_btn.setCallback(std::bind(&MeetingWindow::cb_close, this));
        this->add_person_btn.setCallback(
            std::bind(&MeetingWindow::new_person, this));
    }
    void cb_close() { AnimationWindow::close(); }
    void new_person();
    void print() {
        for (int i = 0; i < people.size(); ++i) {
            std::cout << *(people.at(i));
        }
    }

  private:
    static constexpr int pad = 10;
    static constexpr int btnW = 120;
    static constexpr int btnH = 50;
    static constexpr int fieldW = 100;
    static constexpr int fieldH = 50;

    TDT4102::Button quit_btn;
    TDT4102::Button add_person_btn;
    TDT4102::TextInput person_name;
    TDT4102::TextInput person_email;
    TDT4102::TextInput person_seats;
    std::vector<std::shared_ptr<Person>> people;
};