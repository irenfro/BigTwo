#ifndef DECK_H
#define DECK_H

#include "includes.hpp"
#include "hand.hpp"

#define STANDARD_NUM_CARDS 52

class Deck : public Hand {
    public:
        Deck();

        virtual ~Deck();

        /*
         * Create a standard deck of cards
         */
        void Populate();

        /*
         * Shuffle the deck
         */
        void Shuffle();

        /*
         * Deal a card to the hand
         */
        void Deal(Hand& h);
};

#endif
