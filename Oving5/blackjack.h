#pragma once
#include "card.h"
#include <iostream>
#include <string>

namespace Blackjack {
class BlackjackEngine {
  public:
    std::vector<card::Card> dealer_hand;
    std::vector<card::Card> player_hand;
    card::CardDeck card_deck;
    bool hidden = true;

    BlackjackEngine() { card_deck.shuffle(); }
    void play_game();
    int get_score(std::vector<card::Card> hand);
    void print_state();
    bool ask_to_continue();
    bool check_if_true_blackjack(std::vector<card::Card> hand);
    void you_lose();
    void you_win();

  private:
};
} // namespace Blackjack