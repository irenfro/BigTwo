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
    mCards.reserve(STANDARD_NUM_CARDS);
    populate();
    shuffle();
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
void Deck::populate() {
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
void Deck::shuffle() {
    //seed the random number generator
    std::random_device rd;
    std::mt19937_64 gen(rd());
    int counter = mCards.size()-1;
    for (std::vector<Card*>::iterator it = mCards.begin(); it != mCards.end(); it++, counter--) {
        // get int distribution with new range
        std::uniform_int_distribution<> dis(0, counter);
        const int randomIndex = dis(gen);

        if (*it != mCards.at(randomIndex)) {
            std::swap(mCards.at(randomIndex), *it);
        }
    }
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
void Deck::deal(Hand& h) {
    if(!mCards.empty()) {
        h.add(mCards.back());
        mCards.pop_back();
    } else {
        std::cout << "No more cards. Unable to deal." << std::endl;
    }
}
