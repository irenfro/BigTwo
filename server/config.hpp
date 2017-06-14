#include <string>

class Config {
private:
	void set_opt(int shortopt, char const* optarg);

public:
	bool verbose = false;
	unsigned short port = 0;
	std::string ip;

	Config(int argc, char** argv);
};
