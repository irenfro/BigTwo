#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <string.h>

#include "includes.hpp"

Server::Server(Config const& config) : m_config(config) {
	struct sockaddr_in sa;
	int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketFD == -1) {
		perror("Socket Creation failed.");
		exit(EXIT_FAILURE);
	}

	m_master = SocketFD;

	memset(&sa, 0, sizeof sa);

	sa.sin_family = AF_INET;
	sa.sin_port = htons(config.port);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
		perror("Bind failed.");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	if (listen(SocketFD, 10) == -1) {
		perror("Listen failed.");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

}

Server::~Server() {
}

void Server::run() {
	for (;;) {
		int ConnectFD = accept(m_master, NULL, NULL);
		
		if (0 > ConnectFD) {
			perror("Accept failed.");
			close(m_master);
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "Accepted!");

		/* read and write here */

		if (shutdown(ConnectFD, SHUT_RDWR) == -1) {
			perror("Shutdown failed.");
			close(ConnectFD);
			close(m_master);
			exit(EXIT_FAILURE);
		}
		close(ConnectFD);
	}
	close(m_master);
}
