#include <string>

#include "server.hpp"


int main(void) {
	char* argv[] = {"p", "8888"};
	Config c = Config(2, argv);
	Server s = Server(c);
	s.run();
}
