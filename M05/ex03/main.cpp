#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdlib.h>


int main()
{
	try{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresIdEnTial pardon", "Bender");
		Bureaucrat subject("B1", 1);
		std::cout << subject << std::endl;
		std::cout << *rrf << std::endl;
		subject.signForm(*rrf);
		subject.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();
	
	try{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("jijijaja", "I am your father");
		Bureaucrat subject("B1", 1);
		std::cout << subject << std::endl;
		std::cout << *rrf << std::endl;
		subject.signForm(*rrf);
		subject.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	return (0);
}
