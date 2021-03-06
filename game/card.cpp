#include "card.hpp"

/*
 * Constructor for the Card Class
 *
 * @params:
 *      r -> enum of the rank
 *      s -> enum of the suit
 */

Card::Card(rank r, suit s) {
    mRank = r;
    mSuit = s;
}

/*
 * Return the value of the card
 * This method is specialized for big two
 *
 * @params:
 *      None
 * @return:
 *      3-10 return regular values
 *      Jack, Queen, King are next highest
 *      Ace, Two are the highest cards
 *
 *      Calculates absolute value 
 *      i.e. Ace of Spaces = 48, 2 of Diamonds = 49
 */

int Card::getWeightedValue() const {
    int val = mRank;
    /*
     * Make Ace and Two high cards
     */
    if(val < 3) {
        val += 11;
    } else {
        val -= 2;
    }

    val = (val - 1) * 4 + mSuit;
    return val;
}
/*
 * @return: BOOL whether the first argument is
 * to be placed in front of the second argument
 */
bool Card::compareCards(const Card* c1, const Card* c2) {
    return c1->getWeightedValue() > c2->getWeightedValue();
}

int Card::getValue() const {
    return mRank;
}

int Card::getSuit() const {
    return mSuit;
}

/*
 * Overloads the << operator so we can print Card objects
 * Prints Rank then Suit, can update later to use the unicode 
 *      cards from Unicode 6.0: https://en.wikipedia.org/wiki/Playing_cards_in_Unicode
 *
 * @params:
 *      lhs: a reference to an outputstrem
 *      rhs: a reference to a Card object that we want to print
 *
 * @return:
 *      a reference to an ouputstream
 */
std::ostream& operator<<(std::ostream& os, const Card& c) {
    const std::string val[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    /*
     * The unicode value for the different suits in black
     * Diamonds, Clubs, Hearts, Spades respectively 
     * Sample output: ♦ , ♣ , ♥ , ♠
     *
     * The unicode value for the different suits in white is commented out
     * Diamonds, Clubs, Hearts, Spades respectively 
     * Sample output: ♢ , ♧ , ♡ , ♤
     */
    const std::string suit[] = {"\u2666", "\u2663", "\u2665", "\u2660"};
    /*const std::string suit[] = {"\u2662", "\u2667", "\u2661", "\u2664"};*/

    os << val[c.getValue() - 1] << suit[c.getSuit() - 1];

    return os;
}
