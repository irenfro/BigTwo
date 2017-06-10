#include "game.hpp"

/*
 * Constructor for the game class
 * Takes in a list of player names and then sets up a player for each name
 * Creates and shuffles the deck
 *
 * @params:
 *      playerName -> list of names of the players
 *
 * @return:
 *      None
 */
Game::Game(const std::vector<std::string>& playerNames) {
    std::vector<std::string>::const_iterator it;
    for(it = playerNames.begin(); it != playerNames.end(); it++) {
            players.push_back(Player(*it));
    }
}

/*
 * Destructor for the Game class
 */
Game::~Game() {}

/*
 * All of the logic for the game goes here
 */
void Game::play() {
    deck.printHand();
}
