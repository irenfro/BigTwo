#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "client.hpp"

using std::cout;
using std::cin;

Client::Client(Config const& config) : m_config(config) {
	struct sockaddr_in sa;
	int res;
	int SocketFD;
	char buffer[1025];
	
	SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketFD == -1) {
		perror("Socket Creation failed.");
		exit(EXIT_FAILURE);
	}
	
	memset(&sa, 0, sizeof sa);

	sa.sin_family = AF_INET;
	sa.sin_port = htons(m_config.port);
	res = inet_pton(AF_INET, m_config.ip, &sa.sin_addr);

	if (connect(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
		perror("Connect failed.");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Connected!");

	/* read and write operations go here... */
	int done = 0;

	while(!done) {
		int status = recv(SocketFD, buffer, sizeof(buffer), 0);
		if (status < 0) {
			puts("Receive failed.");
			exit(EXIT_FAILURE);
		}
		else if (status == 0) {
			done = 1;
		}
		else {
			cout << buffer;
		}
	}

	shutdown(SocketFD, SHUT_RDWR);
	close(SocketFD);
}

Client::~Client() {
}
