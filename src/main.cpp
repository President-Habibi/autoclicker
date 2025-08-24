#include "mc_autoclicker.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Starting Habibi's mind-blowing autoclicker..." << std::endl;

	try {
		startAutoclicker();
	} catch(const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
