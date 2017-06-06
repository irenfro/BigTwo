#include "deck.hpp"

/*
 * Constructor for the Deck class
 * 
 * Creates a 52 card deck
 *
 * @params:
 *      None
 *
 * @return:
 *      None
 */
Deck::Deck() {
    mCards.reserve(52);
    Populate();
    Shuffle();
}

/*
 * Destructor for the Deck class
 */
Deck::~Deck() {}

/*
 * Populate the deck with the 52 standard playing cards
 *
 * @params:
 *      None
 *
 * @return:
 *      None
 */
void Deck::Populate() {
    clean();
    for(int s = Card::DIAMONDS; s <= Card::SPADES; s++) {
        for(int r = Card::ACE; r <= Card::KING; r++) {
            add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

/*
 * Shuffles the cards in the deck
 */
void Deck::Shuffle() {
    random_shuffle(mCards.begin(), mCards.end());
}

/*
 * Deal out one card from the deck to the hand
 *
 * @params:
 *      h -> reference to a hand object
 *
 * @return:
 *      None
 */
void Deck::Deal(Hand& h) {
    if(!mCards.empty()) {
        h.add(mCards.back());
        mCards.pop_back();
    } else {
        std::cout << "No more cards. Unable to deal." << std::endl;
    }
}
