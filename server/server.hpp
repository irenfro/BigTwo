#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "config.hpp"

class Server {
	private:
		Config const& m_config;
		int m_master;

	public:
		Server(Config const& config);
		~Server() noexcept;

		void run();
};

#endif
