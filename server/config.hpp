#include <string>

class Config {
private:
	void set_opt(int shortopt, char const* optarg);

public:
	bool verbose = false;
	unsigned short port = 0;

	Config(int argc, char** argv);
};
