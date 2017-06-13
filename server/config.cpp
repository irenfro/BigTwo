#include <iostream>
#include <getopt.h>
#include <sys/socket.h>

#include "config.hpp"

void Config::set_opt(int shortopt, char const* optarg) {
	switch (shortopt) {
		case 'v':
			verbose = true;
			break;
		case 'p':
			port = strtol(optarg, NULL, 10);
			if (port <= 1024 && port != 0) {
				perror("Invalid port");
				exit(EXIT_FAILURE);
			}
			break;
	}
}

Config::Config(int argc, char** argv) {
	int i;
	for (i = 0; i < argc - 1; i += 2) {
		set_opt(argv[i][0], argv[i + 1]);
	}
}
