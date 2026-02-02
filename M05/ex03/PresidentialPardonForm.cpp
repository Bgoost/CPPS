#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("Presidential Pardon Form", 25, 5),
		target("Default Target")
{
	std::cout << YELLOW << "PresidentialPardonForm \'" << target << "\' with grade to sign " << getGradeToSign() << " and grade to execute " << getGradeToExecute() << " successfully created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:	AForm("Presidential Pardon Form", 25, 5),
		target(target)
{
	std::cout << YELLOW << "PresidentialPardonForm \'" << target << "\' with grade to sign " << getGradeToSign() << " and grade to execute " << getGradeToExecute() << " successfully created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	:	AForm(other),
		target(other.target)
{
	std::cout << "PresidentialPardonForm created by copy constructor" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << "PresidentialPardonForm " << RESET << "destructor called " << RED << "(THROWING IT 🗑️ )" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << "Trying to execute Presidential Pardon Form..." << std::endl;
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	std::cout << YELLOW << target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
