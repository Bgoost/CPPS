#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->type = "Dog";
	std::cout << MAGENTA << "Dog of type " << BOLDMAGENTA << this->type << RESET << MAGENTA << " created" << RESET << std::endl;
}

Dog::Dog(const Dog &src)
	: Animal(src)
{
	this->type = src.type;
	std::cout << MAGENTA << "Dog of type " << BOLDMAGENTA << this->type << RESET << MAGENTA << " copy constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BOLDMAGENTA << "Dog " << RESET << "destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << ITALIC << "🐶 Woof! Woof! 🐶" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << MAGENTA << "Dog assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}
