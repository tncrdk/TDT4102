#pragma once
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

namespace card {
enum class Suit { clubs = 1, spades, hearts, diamonds };
enum class Rank {
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};

const std::map<Suit, std::string> SUIT_STRING = {{Suit::clubs, "Clubs"},
                                                 {Suit::spades, "Spades"},
                                                 {Suit::hearts, "Hearts"},
                                                 {Suit::diamonds, "Diamonds"}};
const std::map<Rank, std::string> RANK_STRING = {
    {Rank::two, "Two"},     {Rank::three, "Three"}, {Rank::four, "Four"},
    {Rank::five, "Five"},   {Rank::six, "Six"},     {Rank::seven, "Seven"},
    {Rank::eight, "Eight"}, {Rank::nine, "Nine"},   {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},   {Rank::queen, "Queen"}, {Rank::king, "King"},
    {Rank::ace, "Ace"}};

std::string suit_to_string(const Suit suit);
std::string rank_to_string(const Rank rank);

class Card {
  public:
    Card(Suit suit, Rank rank) : _suit(suit), _rank(rank) {}
    Card() {
        this->_rank = Rank::ace;
        this->_suit = Suit::spades;
    }

    Suit get_suit() const { return this->_suit; }
    Rank get_rank() const { return this->_rank; }
    std::string to_string() const {
        return rank_to_string(this->_rank) + " of " +
               suit_to_string(this->_suit);
    }

  private:
    Suit _suit;
    Rank _rank;
};

class CardDeck {
  public:
    CardDeck();
    void print() const;
    void shuffle();
    Card draw_card();

  private:
    void swap(int i, int j);
    std::vector<Card> _cards;
    std::default_random_engine _rnd_engine;
    std::uniform_int_distribution<int> _rnd_gen;
};
} // namespace card