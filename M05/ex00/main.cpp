#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>


int main()
{
	try {
		Bureaucrat b1("Subject", 3);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}

	std::cin.get();
	try {
		Bureaucrat b2("Bob", 1);
		std::cout << b2;
		b2.incrementGrade();
		std::cout << b2;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}

	std::cin.get();
	try {
		Bureaucrat b2("Patrick", 150);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}

	std::cin.get();
	try {
		Bureaucrat b2("Plankton", -1);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
}
