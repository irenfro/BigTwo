CC = g++
CFLAGS = -Wall -Werror -std=c++11
#C++ Files
CPP = main.cpp card.cpp hand.cpp player.cpp deck.cpp game.cpp
#Header Files for the C++ Files
HEADERS = includes.hpp card.hpp hand.hpp player.hpp deck.hpp game.hpp
#Object Files to match C++ and Header Files
OBJ = main.o card.o hand.o player.o deck.o game.o

all: bigtwo

bigtwo:	$(OBJ) 
	$(CC) $(CFLAGS) -o bigtwo $^

#Dynamically make the Object Files
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o bigtwo
