#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("Robotomy Request Form", 72, 45),
		target("Default Target")
{
	std::cout << YELLOW << "RobotomyRequestForm \'" << target << "\' with grade to sign " << getGradeToSign() << " and grade to execute " << getGradeToExecute() << " successfully created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:	AForm("Robotomy Request Form", 72, 45),
		target(target)
{
	std::cout << YELLOW << "RobotomyRequestForm \'" << target << "\' with grade to sign " << getGradeToSign() << " and grade to execute " << getGradeToExecute() << " successfully created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	:	AForm(other),
		target(other.target)
{
	std::cout << "RobotomyRequestForm created by copy constructor" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm " << RESET << "destructor called " << RED << "(THROWING IT 🗑️ )" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand(time(0));
	int success = rand() % 2;
	std::cout << "Trying to execute Robotomy Request Form..." << std::endl;
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (success)
		std::cout << BOLDGREEN << "Robotomy Request Form executed successfully on " << target << "!" << RESET << std::endl;
	else
		std::cout << BOLDRED << "Womp Womp. Robotomy Request Form execution failed on " << target << "!" << RESET << std::endl;

}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}
