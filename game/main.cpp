
/*
 * Temporary Main file used for compilation
 */

#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"

int main() {
    std::cout << "BigTwo" << std::endl;
    Deck deck;
    Hand hand;
    for(int i = 0; i < 13; i++) {
    	deck.Deal(hand);
	}
	hand.sortHand();
	hand.printHand();
    return 0;
}
