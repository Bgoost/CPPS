#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		if (argc < 2)
			throw std::runtime_error("Usage: ./PmergeMe <positive integers>");
		PmergeMe sorter;
		sorter.loadData(argv);
		sorter.process();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
