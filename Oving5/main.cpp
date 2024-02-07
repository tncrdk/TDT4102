#include "blackjack.h"
#include "card.h"
#include "std_lib_facilities.h"

int main() {
    // Oppg. 1
    // card::Rank r = card::Rank::ace;
    // card::Suit s = card::Suit::spades;

    // std::cout << card::suit_to_string(s) << "\n"
    //           << card::rank_to_string(r) << "\n";

    // Oppg. 2
    // card::Card c(s, r);
    // std::cout << c.to_string() << "\n";

    // Oppg. 3
    // card::CardDeck cd;
    // cd.shuffle();
    // cd.print();

    // Oppg. 4
    Blackjack::BlackjackEngine game;
    game.play_game();
    return 0;
}
