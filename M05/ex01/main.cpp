#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdlib.h>


int main()
{
	try{
		Bureaucrat b1("Creed", 150);
		Form form1("Form1", 1, 1);
		std::cout << b1;
		form1.beSigned(b1);
		std::cout << form1;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		form1.beSigned(b1);
		std::cout << form1;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b2("Angela", 1);
		Form form2("Form2", 0, 1);
		std::cout << b2;
		form2.beSigned(b2);
		std::cout << form2;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		form2.beSigned(b2);
		std::cout << form2;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b3("Andy", 1);
		Form form3("Form3", 1, 151);
		std::cout << b3;
		form3.beSigned(b3);
		std::cout << form3;
		b3.incrementGrade();
		std::cout << b3 << std::endl;
		form3.beSigned(b3);
		std::cout << form3;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b4("Pam", 1);
		Form form4("Form4", 1, 151);
		std::cout << b4;
		form4.beSigned(b4);
		std::cout << form4;
		b4.incrementGrade();
		std::cout << b4 << std::endl;
		form4.beSigned(b4);
		std::cout << form4;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}
	std::cin.get();

	try{
		Bureaucrat b5("Jim", 2);
		Form form("Form", 1, 1);
		std::cout << b5;
		form.beSigned(b5);
		std::cout << form;
		b5.incrementGrade();
		std::cout << b5 << std::endl;
		form.beSigned(b5);
		std::cout << form;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	} catch (...) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "Unknown exception" << BOLDRED << " ]]" << RESET << std::endl;
	}

}
