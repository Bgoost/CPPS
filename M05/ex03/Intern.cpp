#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

AForm*	Intern::newShrubbery( std::string target )
{
	return(new ShrubberyCreationForm(target));
}
AForm*	Intern::newPresidential( std::string target )
{
	return(new PresidentialPardonForm(target));
}
AForm*	Intern::newRobotomy( std::string target )
{
	return(new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm( std::string name, std::string target )
{
    std::string lowerName;
    for (size_t i = 0; i < name.length(); i++)
        lowerName += tolower(name[i]);
    AForm*	(Intern::*f[3])(std::string) = {&Intern::newShrubbery, &Intern::newPresidential, &Intern::newRobotomy};
    std::string names[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    for (int i = 0; i < 3; i++)
    {
        if (lowerName == names[i])
            return (this->*f[i])(target);
    }
    throw (Intern::NonExistentFormException());
    return (NULL);
}

const char*	Intern::NonExistentFormException::what(void) const throw()
{
    return ("This form does not exist");
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
	return (*this);
}


