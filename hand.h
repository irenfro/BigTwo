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

    protected:
        std::vector<Card*> mCards;
};

#endif
