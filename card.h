#ifndef CARD_H
#define CARD_H

#include "common.h"

class Card {
        public:
            /*
             * Enum for the cards 
             */
            enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

            /*
             *  Enum for the suits
             */
            enum suit {DIAMONDS = 1, CLUBS, HEARTS, SPADES};

            /*
             *  Used for printing the cards
             *  
             *  Marked as friend because it needs to be able to read 
             *      the properties of the Card class
             */
            friend std::ostream& operator<<(std::ostream& os, const Card& c);

            /*
             * Constructor
             */
            Card(rank r, suit s);

            /*
             * Returns the value of the card
             *
             * Marked as const because it is a getter
             */
            int getValue() const;

        private:
            /*
             * Member variable for the card's rank
             */
            rank mRank;

            /*
             * Member variable for the card's suit
             */
            suit mSuit
};

#endif
