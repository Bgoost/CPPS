#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdlib.h>


int main()
{
	try{
		Bureaucrat b1("B1", 1);
		PresidentialPardonForm p1("P1");

		std::cout << b1 << std::endl;
		std::cout << p1 << std::endl;
		b1.signForm(p1);
		b1.executeForm(p1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b1("B1", 1);
		RobotomyRequestForm r1("R1");

		std::cout << b1 << std::endl;
		std::cout << r1 << std::endl;
		b1.signForm(r1);
		b1.executeForm(r1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b1("B1", 1);
		ShrubberyCreationForm s1("S1");

		std::cout << b1 << std::endl;
		std::cout << s1 << std::endl;
		b1.signForm(s1);
		b1.executeForm(s1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b1("B1", 1);
		PresidentialPardonForm p1("P1");

		std::cout << p1 << std::endl;

		b1.executeForm(p1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b1("B1", 1);
		ShrubberyCreationForm s1("S1");

		std::cout << s1 << std::endl;
		b1.signForm(s1);
		b1.executeForm(s1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();
	std::cout << BOLD << "WARNING!! DO CHMOD 000 FILE_SHRUBBERY" << RESET << std::endl;
	std::cin.get();

	try{
		Bureaucrat b1("B1", 50);
		RobotomyRequestForm r1("R1");

		std::cout << r1 << std::endl;
		b1.signForm(r1);
		b1.executeForm(r1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b1("B1", 150);
		PresidentialPardonForm p1("P1");

		std::cout << p1 << std::endl;
		b1.signForm(p1);
		b1.executeForm(p1);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}


	return (0);
}
