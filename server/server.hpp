#include <string>
#include "includes.hpp"

class Server {
	private:
		Config const& m_config;
		int m_master;

	public:
		Server(Config const& config);
		~Server() noexcept;

		void run();
};
