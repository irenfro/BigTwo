#include "player.hpp"

/*
 * Constructor for the Player Class
 *
 * @params:
 *      name -> a reference to the name of the player
 *
 * @return:
 *      None
 */
Player::Player(const std::string& name): mName(name), mPass(false) {}

/*
 * Destructor for the Player Class
 */
Player::~Player() {}

/*
 * Function that returns whether the player 
 *      has passed this round or not
 *
 * @params:
 *      None
 *
 * @return:
 *      the value of the pass variable
 */
bool Player::hasPassed() {
        return mPass;
}

/*
 * Function to set the pass variable 
 *      for the player
 * 
 * @params:
 *      p -> the value to set pass to
 *
 * @return:
 *      None
 */
void Player::setPass(bool p) {
        if(mCards.size() == 0) {
            mPass = true;
        } else {
            mPass = p;
        }
}

/*
 * Overloads the << operator so that a Player object 
 *      can be sent to stdout
 * If the hand is empty print "<name>:\t<empty>"
 * Otherwise use the format "<name>:\t<card>\t...<card>\t"
 *
 * @params:
 *      lhs -> a reference to an output stream
 *      rhs -> a reference to a player
 *
 * @return:
 *      a reference to an output stream
 */
std::ostream& operator<<(std::ostream& os, const Player& p) {
        os << p.mName << ":\t";

        if(!p.mCards.empty()) {
            /*
             * Loop to iterate through the cards and add them to the stream
             */
            std::vector<Card*>::const_iterator it;
            for(it = p.mCards.begin(); it != p.mCards.end(); it++) {
                    /*
                     * We need a reference to a card to use the 
                     *      operator overload in the card class
                     */
                    os << *(*it) << "\t";
            }
        } else {
            os << "<empty>";
        }
        return os;
}
