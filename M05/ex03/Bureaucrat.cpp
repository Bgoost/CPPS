#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	name("Mandarino"),
		grade(150)
{
	std::cout << MAGENTA << "Default Bureaucrat " << name << " with grade " << grade << " successfully created by god" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:	name(name),
		grade(grade)
{
	std::cout << "Trying to create Bureaucrat " << name << "..." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << MAGENTA << "Bureaucrat " << name << " with grade " << grade << " successfully created by god" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	:	name(other.name),
		grade(other.grade)
{
	std::cout << MAGENTA << "Bureaucrat created by copy constructor" << RESET << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << MAGENTA << "Bureaucrat " << RESET << "destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low");
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Trying to increment " << name << "'s grade..." << std::endl;
	if (grade == 1)
		throw std::out_of_range("Grade is already at the highest level");
	grade--;
	std::cout << "Successfully incremented " << name << "'s grade to " << grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Trying to decrement " << name << "'s grade..." << std::endl;
	if (grade >= 150)
		throw std::out_of_range("Grade is already at the lowest level");
	grade++;
	std::cout << "Successfully decrementing " << name << "'s grade to " << grade << std::endl;

}

void Bureaucrat::signForm(AForm &form) const
{
	try{
		std::cout << "Trying to sign \'" << form.getName() << "\' AForm..." << std::endl;
		form.beSigned(*this);
		std::cout << GREEN << name << " signed the AForm \'" << form.getName() << "\'" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "couldn't sign \'" << form.getName() << "\' because: " << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try{
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << "couldn't execute \'" << form.getName() << "\' because: " << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& var)
{
	os << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return (os);
}
