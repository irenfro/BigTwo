#ifndef HAND_H
#define HAND_H

#include "card.h"
#include "includes.h"

class Hand {
    public:
        Hand();

        virtual ~Hand();
        
        /*
         * Adds A card to the hand
         */
        void add(Card* c);

        /*
         * Removes all cards
         */
        void clean();

        /*
         * Returns how many cards are left in the hand
         */
        int getCardsLeft();

        /*
         * Sort hand by Rank then by suit in order from diamond, clubs, hearts, spades  
         */
        void sortHand();

    protected:
        std::vector<Card*> mCards;
};

#endif
