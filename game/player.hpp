#ifndef PLAYER_H
#define PLAYER_H

#include "includes.hpp"
#include "hand.hpp"

class Player : public Hand {

        /*Overloading the << operator so we can print players*/
        friend std::ostream& operator<<(std::ostream& os, const Player& p);

        public:
            Player(const std::string& name);

            virtual ~Player();

            bool hasPassed();

            void setPass(bool p);

        protected:
            std::string mName;

        private:
            bool mPass;
};

#endif
