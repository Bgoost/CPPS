#include "Animal.hpp"

Animal::Animal()
	:	type("Animal")
{
	std::cout << "Animal of type " << BOLDWHITE << this->type << RESET << " created" << std::endl;
}

Animal::Animal(const Animal &src)
	:	type(src.type)
{
	*this = src;
	std::cout << "Animal of type " << BOLDWHITE << this->type << RESET << " copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << BOLDWHITE << "Animal " << RESET << " destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}


void Animal::makeSound() const
{
	std::cout << BOLDWHITE << this->type << RESET << " makes sound: " << BOLDWHITE << "random animal sound..." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
