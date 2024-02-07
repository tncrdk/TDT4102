#include "card.h"
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

namespace card {
std::string suit_to_string(Suit suit) { return SUIT_STRING.at(suit); }

std::string rank_to_string(const Rank rank) { return RANK_STRING.at(rank); }

CardDeck::CardDeck() {
    std::map<Rank, std::string>::const_iterator it;
    std::map<Suit, std::string>::const_iterator jt;
    int index = 0;
    for (it = RANK_STRING.begin(); it != RANK_STRING.end(); it++) {
        for (jt = SUIT_STRING.begin(); jt != SUIT_STRING.end(); jt++) {
            this->_cards.push_back(Card(jt->first, it->first));
        }
    }
}

void CardDeck::swap(int i, int j) {
    Card temp = this->_cards.at(i);
    this->_cards.at(i) = this->_cards.at(j);
    this->_cards.at(j) = temp;
}

void CardDeck::print() const {
    for (std::vector<Card>::const_iterator it = this->_cards.begin();
         it != this->_cards.end(); ++it) {
        std::cout << it->to_string() << "\n";
    }
}

void CardDeck::shuffle() {
    std::random_device seed;
    std::default_random_engine generator(seed());
    std::uniform_int_distribution<int> dist(0, this->_cards.size() - 1);
    for (int i = 0; i < this->_cards.size(); ++i) {
        int j = dist(generator);
        this->swap(i, j);
    }
}

Card CardDeck::draw_card() {
    Card card = this->_cards.at(this->_cards.size() - 1);
    this->_cards.pop_back();
    return card;
}
} // namespace card