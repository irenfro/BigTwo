#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "config.hpp"

class Server {
	private:
		Config const& m_config;
		int m_master;
		int turn;
		fd_set readfds;
		int max_clients;
		int[] client_socket;

	public:
		Server(Config const& config);
		~Server() noexcept;

		void run();
};

#endif
