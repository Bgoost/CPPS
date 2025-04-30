#include "Animal.hpp"

A_Animal::A_Animal()
	:	type("A_Animal")
{
	std::cout << "A_Animal of type " << BOLDWHITE << this->type << RESET << " created" << std::endl;
}

A_Animal::A_Animal(const A_Animal &src)
	:	type(src.type)
{
	*this = src;
	std::cout << "A_Animal of type " << BOLDWHITE << this->type << RESET << " copy constructor called" << std::endl;
}

A_Animal::~A_Animal()
{
	std::cout << BOLDWHITE << "A_Animal " << RESET << " destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}


void A_Animal::makeSound() const
{
	std::cout << BOLDWHITE << this->type << RESET << " makes sound: " << BOLDWHITE << "random A_animal sound..." << RESET << std::endl;
}

std::string A_Animal::getType() const
{
	return (this->type);
}

A_Animal &A_Animal::operator=(const A_Animal &other)
{
	std::cout << "A_Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
