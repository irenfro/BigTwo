#ifndef HAND_H
#define HAND_H

#include "card.hpp"
#include "includes.hpp"

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

        /*
         * Prints whole hand
         */
        void printHand();

        /*
         * Getter and Setter for numCards
         */
        void setNumCards(int);

        int getNumCards();

    protected:
        std::vector<Card*> mCards;
        const static int NUM_CARDS_PER_LINE = 8;
    
    private:
        int numCards;
};

#endif
