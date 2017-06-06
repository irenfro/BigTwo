#ifndef CARD_H
#define CARD_H

#include "includes.hpp"

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
             */
            friend std::ostream& operator<<(std::ostream& os, const Card& c);

            /*
             * Constructor
             */
            Card(rank r, suit s);

            /*
             * Returns the weighted value of the card
             *
             * Marked as const because it is a getter
             */
            int getWeightedValue() const;

            /*
             * Returns the non weighted value of the card
             *
             * Marked as const because it is a getter
             */
            int getValue() const;

            /*
             * Returns the suit value
             */
            int getSuit() const;

            /*
             * Returns whether the first argument is
             * to be placed in front of the second argument
             */
            bool compareCards(const Card* c1, const Card* c2);

        private:
            /*
             * Member variable for the card's rank
             */
            rank mRank;

            /*
             * Member variable for the card's suit
             */
            suit mSuit;
};

#endif
