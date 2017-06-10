#ifndef GAME_H
#define GAME_H

#include "includes.hpp"
#include "deck.hpp"
#include "player.hpp"

class Game {
    public:
        /*
         * Constructor for the game class
         */
        Game(const std::vector<std::string>& playerNames);

        /*
         * Destructor for the game class
         */
        ~Game();

        /*
         * The main logic for the game
         */
        void play();

    private:
        Deck deck;
        std::vector<Player> players;
};

#endif
