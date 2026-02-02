#include "Form.hpp"

Form::Form()
	:	name("Lower Form"),
		gradeToSign(150),
		gradeToExecute(150),
		isSigned(false)
{
	std::cout << CYAN << "Form \'" << name << "\' with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << " successfully created" << RESET << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	:	name(name),
		gradeToSign(gradeToSign),
		gradeToExecute(gradeToExecute),
		isSigned(false)
{
	std::cout << "Trying to create Form \'" << name << "\'..." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << CYAN << "Form \'" << name << "\' with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << " successfully created" << RESET << std::endl;
}

Form::Form(const Form &other)
	:	name(other.name),
		gradeToSign(other.gradeToSign),
		gradeToExecute(other.gradeToExecute),
		isSigned(other.isSigned)
{
	std::cout << "Form created by copy constructor" << std::endl;
	*this = other;
}

Form::~Form()
{
	std::cout << CYAN << "Form " << RESET << "destructor called " << RED << "(THROWING IT 🗑️ )" << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	try{
		if (bureaucrat.getGrade() > gradeToSign)
			throw Form::GradeTooLowException();
		isSigned = true;
		std::cout << GREEN << bureaucrat.getName() << " signed the Form \'" << name << "\'" << RESET << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << BOLDRED << "[[ EXCEPTION FOUND: " << RESET << RED << bureaucrat.getName() << " couldn't sign the form \'" << name << "\' because: " << e.what() << BOLDRED << " ]]" << RESET << std::endl;
	}

}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: '" << form.getName() << "\'" << std::endl;
	if (form.getIsSigned())
		os << "• Status: " << GREEN << "signed" << RESET << std::endl;
	else
		os << "• Status: " << RED << "unsigned" << RESET << std::endl;
	os << "• Required signature grade: " << form.getGradeToSign() << std::endl;
	os << "• Required execution grade: " << form.getGradeToExecute() << std::endl;

	return (os);
}
