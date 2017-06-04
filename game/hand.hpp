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

    protected:
        std::vector<Card*> mCards;
};

#endif
