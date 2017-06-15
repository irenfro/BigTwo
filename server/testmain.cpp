#include <string>
#include <iostream>

#include "server.hpp"
#include "client.hpp"
#include "config.hpp"

using std::cout;
using std::cin;

int main(void) {
	char choice = 0;
	std::string inp("");
	cout << "Welcome to Big Two!\n\n";
	cout << "\t(1) Start a server.\n";
	cout << "\t(2) Join a server.\n";
	cout << "\t(3) Exit\n\n";
	cout << "Select a choice: ";
	cin >> inp;
	choice = inp[0];
	
	if (choice == '1') {
		cout << "\nEnter a port: ";
		cin >> inp;
		const char* argv[] = {"p", inp.c_str()};
		Config c = Config(2, argv);
		Server s = Server(c);
		s.run();
	}
	else if (choice == '2') {
		std::string ip("");
		cout << "\nEnter an ip address: ";
		cin >> ip;
		cout << "\nEnter a port: ";
		cin >> inp;
		const char* argv[] = {"i", ip.c_str(), "p", inp.c_str()};
		Config c = Config(4, argv);
		Client cl = Client(c);
	}
	else {
		exit(0);
	}
	return 0;
}
