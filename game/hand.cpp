#include "hand.h"

/*
 * Constructor
 */
Hand::Hand() {
    /*
     * Make sure the vector can hold the 
     * 13 cards for 4 players
     */
    mCards.reserve(13);
}

/*
 * Destructor
 */
Hand::~Hand() {
    clean();
}

/*
 * Adds a card to the hand
 *
 * @params:
 *      c -> pointer to card to add to the hand
 * @return:
 *      None
 */
void Hand::add(Card* c) {
    if(c != nullptr) {
        mCards.push_back(c);
    }
}

/*
 * Removes all of the acrds from the Hand
 * Should also delete the memory used by the 
 *      vector and cards
 *
 * @params:
 *      None
 * @return:
 *      None
 */
void Hand::clean() {
    std::vector<Card*>::iterator it = mCards.begin();
    for(; it != mCards.end(); it++) {
        delete *it;
        *it = nullptr;
    }
    mCards.clear();
}

/*
 * Returns the number of cards left in the hand
 *
 * @params:
 *      None
 *
 * @return:
 *      the size of the card vector
 */
int Hand::getCardsLeft() {
        return mCards.size();
}

/*
 * Sort hand by Rank then by suit in order from diamond, clubs, hearts, spades  
 */
void Player::sortHand() {
    
}
