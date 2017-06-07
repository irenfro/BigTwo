#include "main.hpp"
/*
 * Temporary Main file used for compilation
 */


int main() {
    std::cout << "BigTwo" << std::endl;
    /*-----------Keep-----------*/
    /*
     * Seed the random shuffle
     */
    //srand(time(0));

    int players = 0;
    std::string temp;
    while(players < 1 || players > 5) {
        std::cout << "How many players? (1 - 5): ";
        std::getline(std::cin, temp);
        try {
            players = stoi(temp);
        } catch(std::invalid_argument) {
           players = 0; 
        }
    }

    std::vector<std::string> playerNames;
    for(int i = 0; i < players; i++) {
        std::cout << "Enter a player's name: ";
        std::cin >> temp;
        playerNames.push_back(temp);
    }

    /*
     * Start a game with the vector of player names
     */
    char playAgain;
    do {
        /*
         * Start game loop
         */
         std::cout << "Would you like to play again? (Y/N): ";
         std::cin >> playAgain;
    } while(playAgain == 'y' || playAgain == 'Y');
    

    Deck deck;
    Hand hand;
    hand.setNumCards(13);
    for(int i = 0; i < 13; i++) {
    	deck.Deal(hand);
	}
	hand.sortHand();
	hand.printHand();
    return 0;
}
