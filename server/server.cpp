#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <string.h>

#include "server.hpp"

Server::Server(Config const& config) : m_config(config) {
	turn = 0;
	max_clients = 3;

	int i;
	for (i = 0; i < max_clients; i++) {
		client_socket[i] = 0;
	}

	struct sockaddr_in sa;
	int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketFD == -1) {
		perror("Socket Creation failed.");
		exit(EXIT_FAILURE);
	}

	m_master = SocketFD;

	int opt = 1;
	if (setsockopt(m_master, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0) {
		perror("Socket option failed.");
		exit(EXIT_FAILURE);
	}

	memset(&sa, 0, sizeof sa);

	sa.sin_family = AF_INET;
	sa.sin_port = htons(config.port);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
		perror("Bind failed.");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	if (listen(SocketFD, 3) == -1) {
		perror("Listen failed.");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

}

Server::~Server() {
}

void Server::run() {
	int activity = 0;
	int new_socket = 0;
	int addrlen = 0;
	int max_sd = 0;
	struct sockaddr_in address;
	char* message = "Welcome to Big Two!\r\n";
	int sd;
	int valread;
	char buffer[1025];

	for (;;) {
		FD_ZERO(&readfds);

		FD_SET(m_master, &readfds);
		max_sd = m_master;
		
		int i;
		for (i = 0; i < max_clients; i++) {
			sd = client_socket[i];
			if (sd > 0) {
				FD_SET(sd, &readfds);
			}
			
			if (sd > max_sd) {
				max_sd = sd;
			}
		}

		activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
		
		if ((activity < 0) && (errno != EINTR)) {
			printf("Select failed.");
		}

		if (FD_ISSET(m_master, &readfds)) {
			if ((new_socket = accept(m_master,
				(struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
				perror("Accept failed.");
				exit(EXIT_FAILURE);
			}

			printf("New Connection\nSocket File Descriptor: %d\nIP Address: %s\nPort: %d\n",
				new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

			if (send(new_socket, message, strlen(message), 0) != strlen(message)) {
				perror("Send failed.");
			}
			
			puts("Welcome message sent successfully\n");

			for (i = 0; i < max_clients; i++) {
				if (client_socket[i] == 0) {
					client_socket[i] = new_socket;
					printf("Adding to list of sockets as %d\n", i);
					break;
				}
			}
		}

		for (i = 0; i < max_clients; i++) {
			sd = client_socket[i];
			
			if (FD_ISSET(sd, &readfds)) {
				if ((valread = read(sd, buffer, 1024)) == 0) {
					getpeername(sd, (struct sockaddr*)&address, \
						(socklen_t*)&addrlen);
						printf("Host Disconnected\nIP Address: %s\nPort: %d\n",
						inet_ntoa(address.sin_addr), ntohs(address.sin_port));

					close(sd);
					client_socket[i] = 0;
				}
				else {
					buffer[valread] = '\0';
					send(sd, buffer, strlen(buffer), 0);
				}
			}
		}

		/*

		int ConnectFD = accept(m_master, NULL, NULL);
		
		if (0 > ConnectFD) {
			perror("Accept failed.");
			close(m_master);
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "Accepted!");

		*/

		/* read and write here */

		/* end read/write */

		/*

		if (shutdown(ConnectFD, SHUT_RDWR) == -1) {
			perror("Shutdown failed.");
			close(ConnectFD);
			close(m_master);
			exit(EXIT_FAILURE);
		}
		close(ConnectFD);

		*/
	}
	close(m_master);
}
