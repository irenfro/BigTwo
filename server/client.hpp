#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "config.hpp"

class Client {
	private:
		Config const& m_config;

	public:
		Client(Config const& config);
		~Client() noexcept;
};

#endif
