#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	struct sockaddr_in sa;
	int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketFD == -1) {
		perror("Socket Creation failed.");
		exit(EXIT_FAILURE);
	}

	memset(&sa, 0, sizeof sa);

	sa.sin_family = AF_INET;
	sa.sin_port = htons(1100);
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

	for (;;) {
		int ConnectFD = accept(SocketFD, NULL, NULL);
		
		if (0 > ConnectFD) {
			perror("Accept failed.");
			close(SocketFD);
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "Accepted!");

		/* read and write here */

		if (shutdown(ConnectFD, SHUT_RDWR) == -1) {
			perror("Shutdown failed.");
			close(ConnectFD);
			close(SocketFD);
			exit(EXIT_FAILURE);
		}
		close(ConnectFD);
	}
	close(SocketFD);
	return EXIT_SUCCESS;
}
