#include "AForm.hpp"

AForm::AForm()
	:	name("Lower AForm"),
		gradeToSign(150),
		gradeToExecute(150),
		isSigned(false)
{
	std::cout << CYAN << "AForm \'" << name << "\' with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << " successfully created" << RESET << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	:	name(name),
		gradeToSign(gradeToSign),
		gradeToExecute(gradeToExecute),
		isSigned(false)
{
	std::cout << "Trying to create AForm \'" << name << "\'..." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << CYAN << "AForm \'" << name << "\' with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << " successfully created" << RESET << std::endl;
}

AForm::AForm(const AForm &other)
	:	name(other.name),
		gradeToSign(other.gradeToSign),
		gradeToExecute(other.gradeToExecute),
		isSigned(other.isSigned)
{
	std::cout << "AForm created by copy constructor" << std::endl;
	*this = other;
}

AForm::~AForm()
{
	std::cout << CYAN << "AForm " << RESET << "destructor called " << RED << "(THROWING IT 🗑️ )" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const std::string &AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm: '" << form.getName() << "\'" << std::endl;
	if (form.getIsSigned())
		os << "• Status: " << GREEN << "signed" << RESET << std::endl;
	else
		os << "• Status: " << RED << "unsigned" << RESET << std::endl;
	os << "• Required signature grade: " << form.getGradeToSign() << std::endl;
	os << "• Required execution grade: " << form.getGradeToExecute() << std::endl;

	return (os);
}
