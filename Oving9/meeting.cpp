#include "meeting.h"

std::vector<std::string> Meeting::get_participants_list() const {
    size_t size = this->participants.size();
    std::vector<std::string> result;
    result.reserve(size);
    for (int i = 0; i < size; ++i) {
        result.emplace_back(this->participants.at(i)->get_name());
    }
    return result;
}

std::vector<std::shared_ptr<Person>>
Meeting::find_CoDriver(const Meeting &meeting) const {
    size_t size = this->participants.size();
    std::vector<std::shared_ptr<Person>> co_drivers;
    if (meeting.get_location() != this->get_location()) {
        return co_drivers;
    }
    if (meeting.get_day() != this->get_day()) {
        return co_drivers;
    }
    if (abs(meeting.get_start_time() - this->get_start_time()) > 100) {
        return co_drivers;
    }
    if (abs(meeting.get_end_time() - this->get_end_time()) > 100) {
        return co_drivers;
    }
    co_drivers.reserve(size);
    for (int i = 0; i < meeting.participants.size(); ++i) {
        std::shared_ptr<Person> person_ptr = meeting.participants.at(i);
        if (person_ptr->has_available_seats()) {
            co_drivers.emplace_back(person_ptr);
        }
    }
    return co_drivers;
}

std::ostream &operator<<(std::ostream &os, const Campus &c) {
    os << campus_names[static_cast<int>(c)] << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Meeting &m) {
    os << "Day: " << m.get_day() << "\nStart time: " << m.get_start_time()
       << "\nEnd time: " << m.get_end_time()
       << "\nLocation: " << m.get_location() << "Subject: " << m.get_subject()
       << "\nLeader: " << m.get_leader()->get_name() << "\nParticipants: [";

    std::vector<std::string> participants = m.get_participants_list();
    for (int i = 0; i < participants.size(); ++i) {
        os << "\n   " << participants.at(i);
    }
    os << "\n]\n";

    return os;
}