#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

// int main(int argc, char** argv) {
// 	if (argc < 2) {
// 		std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
// 		return 1;
// 	}
// 	unsigned int size = 0;
// 	std::vector<int> numbers;
// 	for (int i = 1; i < argc; ++i)
// 	{
// 		std::istringstream iss(argv[i]);
// 		int num;

// 		if (!(iss >> num)) {
// 			std::cerr << "Invalid argument: " << argv[i]
// 					<< ". Please provide only integers." << std::endl;
// 			return 1;
// 		}
// 		char c;
// 		if (iss >> c) {
// 			std::cerr << "Invalid argument: " << argv[i]
// 					<< ". Please provide only integers." << std::endl;
// 			return 1;
// 		}
// 		numbers.push_back(num);
// 	}
// 	size = numbers.size();

	

// 	std::cout << BLUE << "====================================================" << RESET << std::endl;
// 	std::cout << BLUE << "\t\tCUSTOM SPAN TEST" << RESET << std::endl;
// 	std::cout << BLUE << "====================================================" << RESET << std::endl;

// 	Span sp(size);
// 	sp.addRange(numbers.begin(), numbers.end());
// 	std::cout << "Numbers added: [";
// 	for(unsigned int i = 0; i < size; ++i)
// 			std::cout << numbers[i] << (i < size - 1 ? ", " : "");
// 	std::cout << "]" << std::endl;
// 	std::cout << GREEN << "────────────────────────────────────────────────────" << RESET << std::endl;
// 	try {
// 		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
// 		std::cout << "Longest span  = " << sp.longestSpan() << std::endl;
// 	} catch (const std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	std::cout << BLUE << "====================================================" << RESET << std::endl;
// 	std::cout << BLUE << "\t     ✅ Span test finished" << RESET << std::endl;
// 	std::cout << BLUE << "====================================================" << RESET << std::endl;

// 	return 0;
// }



int main() {
    std::srand(std::time(0));

    std::cout << BLUE << "====================================================" << RESET << std::endl;
    std::cout << BLUE << "\t\t    SPAN TEST" << RESET << std::endl;
    std::cout << BLUE << "====================================================" << RESET << std::endl;

    {
        std::cout << YELLOW << "\n[Basic test from subject]" << RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

		std::cout << "Numbers = [";
		for(unsigned int i = 0; i < sp.getMaxSize(); ++i)
			std::cout << sp.getNumbers()[i] << (i < sp.getMaxSize() - 1 ? ", " : "");
		std::cout << "]" << std::endl;
        std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span  = " << sp.longestSpan() << std::endl;
		std::cout << GREEN << "────────────────────────────────────────────────────" << RESET << std::endl;
    }

    // === Small basic test ===
    {
        std::cout << YELLOW << "\n[Another basic test]" << RESET << std::endl;
        Span sp(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(25);

        std::cout << "Numbers = [";
		for(unsigned int i = 0; i < sp.getMaxSize(); ++i)
			std::cout << sp.getNumbers()[i] << (i < sp.getMaxSize() - 1 ? ", " : "");
		std::cout << "]" << std::endl;
        std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span  = " << sp.longestSpan() << std::endl;
		std::cout << GREEN << "────────────────────────────────────────────────────" << RESET << std::endl;
    }

    // === Exception tests ===
    {
        std::cout << YELLOW << "\n[Exception test]" << RESET << std::endl;
        try {
            Span sp(1);
            sp.addNumber(42);
            sp.addNumber(84); // should throw
        } catch (std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        try {
            Span sp(0);
            sp.shortestSpan(); // should throw
        } catch (std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
		std::cout << GREEN << "────────────────────────────────────────────────────" << RESET << std::endl;

    }

    // === Stress test with 10,000 numbers ===
    {
        std::cout << YELLOW << "\n[Stress test: 10,000 numbers]" << RESET << std::endl;
        Span sp(10000);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(rand());
        std::vector<int> nums = sp.getNumbers();
        int minVal = *std::min_element(nums.begin(), nums.end());
	    int maxVal = *std::max_element(nums.begin(), nums.end());
        std::cout << "Min value = " << minVal << ", Max value = " << maxVal << std::endl;
        std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span  = " << sp.longestSpan() << std::endl;
		std::cout << GREEN << "────────────────────────────────────────────────────" << RESET << std::endl;
    }

    // === Extreme stress test with range insert ===
    {
        std::cout << YELLOW << "\n[Extreme stress test: 100,000 numbers]" << RESET << std::endl;
        Span sp(100000);
        std::vector<int> vec;
        vec.reserve(100000);
        for (int i = 0; i < 100000; ++i)
            vec.push_back(rand());

        sp.addRange(vec.begin(), vec.end());
        std::vector<int> nums = sp.getNumbers();
        int minVal = *std::min_element(nums.begin(), nums.end());
	    int maxVal = *std::max_element(nums.begin(), nums.end());
        std::cout << "Min value = " << minVal << ", Max value = " << maxVal << std::endl;
        std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span  = " << sp.longestSpan() << std::endl;
    }

	std::cout << BLUE << "====================================================" << RESET << std::endl;
	std::cout << BLUE << "\t     ✅ Span tests finished" << RESET << std::endl;
	std::cout << BLUE << "====================================================" << RESET << std::endl;
    return 0;
}
