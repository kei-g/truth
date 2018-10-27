#include "truth.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	void *p = nullptr;
	algorithm::when(p, []() {
		std::cout << "hoge" << std::endl;
	});
	return 0;
}
