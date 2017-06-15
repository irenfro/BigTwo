#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
private:
	void set_opt(int shortopt, char const* optarg);

public:
	bool verbose = false;
	unsigned short port = 0;
	const char* ip;

	Config(int argc, char const** argv);
};

#endif
