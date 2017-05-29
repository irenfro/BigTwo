CC = g++
CFLAGS = -Wall -Werror -std=c++11
#C++ Files
CPP = main.cpp card.cpp hand.cpp player.cpp deck.cpp
#Header Files for the C++ Files
HEADERS = includes.h card.h hand.h player.h deck.h
#Object Files to match C++ and Header Files
OBJ = main.o card.o hand.o player.o deck.o

all: bigtwo

bigtwo:	$(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o bigtwo $(OBJ)

#Dynamically make the Object Files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o bigtwo
