#include "Dog.hpp"

Dog::Dog()
	: A_Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << MAGENTA << "Dog of type " << BOLDMAGENTA << this->type << RESET << MAGENTA << " created" << RESET << std::endl;
}

Dog::Dog(const Dog &src)
	: A_Animal(src)
{
	this->type = src.type;
	this->brain = new Brain();
	std::cout << MAGENTA << "Dog of type " << BOLDMAGENTA << this->type << RESET << MAGENTA << " copy constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << BOLDMAGENTA << "Dog " << RESET << "destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << ITALIC << "🐶 Woof! Woof! 🐶" << RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << MAGENTA << "Dog assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*(this->brain) = *other.getBrain();
	}
	return (*this);
}
