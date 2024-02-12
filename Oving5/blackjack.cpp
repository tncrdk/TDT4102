#include "blackjack.h"
#include "card.h"
#include <iostream>
#include <string>
#include <vector>

namespace Blackjack {
void BlackjackEngine::play_game() {
    dealer_hand.push_back(card_deck.draw_card());
    dealer_hand.push_back(card_deck.draw_card());
    player_hand.push_back(card_deck.draw_card());
    player_hand.push_back(card_deck.draw_card());

    while (get_score(player_hand) <= 21 && get_score(dealer_hand) <= 21) {
        print_state();
        if (!ask_to_continue()) {
            std::cout << "\n\n";
            break;
        }
        player_hand.push_back(card_deck.draw_card());

        if (get_score(dealer_hand) < 17) {
            dealer_hand.push_back(card_deck.draw_card());
        }
        std::cout << "\n\n";
    }
    int player_score = get_score(player_hand);
    int dealer_score = get_score(dealer_hand);

    hidden = false;
    print_state();

    if (player_score > 21 || check_if_true_blackjack(dealer_hand)) {
        return you_lose();
    }
    if (dealer_score > 21 || check_if_true_blackjack(player_hand) ||
        player_score > dealer_score) {
        return you_win();
    }
    return you_lose();
}

bool BlackjackEngine::ask_to_continue() {
    char input;
    std::cout << "Vil du trekke inn flere kort? [Y/n]";
    std::cin >> input;
    if (std::toupper(input) == 'Y') {
        return true;
    } else {
        return false;
    }
}

bool BlackjackEngine::check_if_true_blackjack(std::vector<card::Card> hand) {
    if (hand.size() != 2) {
        return false;
    }
    if (hand.at(0).get_rank() == card::Rank::ace &&
        int(hand.at(1).get_rank()) >= 10) {
        return true;
    }
    if (hand.at(1).get_rank() == card::Rank::ace &&
        int(hand.at(0).get_rank()) >= 10) {
        return true;
    }
    return false;
}

int BlackjackEngine::get_score(std::vector<card::Card> hand) {
    int aces = 0;
    int score = 0;
    for (int i = 0; i < hand.size(); ++i) {
        card::Rank rank = hand.at(i).get_rank();
        if (rank == card::Rank::ace) {
            ++aces;
            score += 11;
        } else if (int(rank) >= 10) {
            score += 10;
        } else {
            score += int(rank);
        }
    }
    if (score > 21 && aces >= 1) {
        int aces_reduction = (score - 21) / 10 + 1;
        if (aces_reduction > aces) {
            return score - aces * 10;
        }
        return score - 10 * aces_reduction;
    }
    return score;
}

void BlackjackEngine::print_state() {
    std::cout << "Your hand:\n";
    for (int i = 0; i < player_hand.size(); ++i) {
        std::cout << player_hand.at(i).to_string() << "\n";
    }
    std::cout << "\n";
    std::cout << "Dealers hand:\n";
    if (hidden) {
        std::cout << "(HIDDEN)\n";
    }
    for (int i = (hidden ? 1 : 0); i < dealer_hand.size(); ++i) {
        std::cout << dealer_hand.at(i).to_string() << "\n";
    }
}

void BlackjackEngine::you_win() {
    std::cout << "Hurra!! Du vant med en score på " << get_score(player_hand)
              << " mot dealerens sin score " << get_score(dealer_hand) << "\n";
}

void BlackjackEngine::you_lose() {
    std::cout << "Du tapte med en score på " << get_score(player_hand)
              << " mot dealerens sin score " << get_score(dealer_hand) << "\n";
}
} // namespace Blackjack