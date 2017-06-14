#include <string>
#include "includes.hpp"

class Config {
	private:
		Config const& m_config;

	public:
		Client(Config const& config);
		~Client() noexcept;
};
