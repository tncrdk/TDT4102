#pragma once
#include "objects.h"
#include <vector>

enum class Campus { Trondheim = 0, Gjøvik, Ålesund };
const std::string campus_names[] = {"Trondheim", "Gjøvik", "Ålesund"};

class Meeting {
  public:
    Meeting(int day, int start_time, int end_time, Campus location,
            std::string subject, std::shared_ptr<Person> leader)
        : day{day}, start_time{start_time}, end_time{end_time},
          location{location}, subject{subject}, leader{leader} {
        this->add_participant(leader);
    }
    int get_day() const { return this->day; }
    int get_start_time() const { return this->start_time; }
    int get_end_time() const { return this->end_time; }
    Campus get_location() const { return this->location; }
    std::string get_subject() const { return this->subject; }
    const std::shared_ptr<Person> get_leader() const { return this->leader; }
    std::vector<std::string> get_participants_list() const;

    void add_participant(std::shared_ptr<Person> participant) {
        this->participants.emplace_back(participant);
    }
    std::vector<std::shared_ptr<Person>>
    find_CoDriver(const Meeting &meeting) const;

  private:
    int day;
    int start_time;
    int end_time;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;
};

std::ostream &operator<<(std::ostream &os, const Meeting &m);