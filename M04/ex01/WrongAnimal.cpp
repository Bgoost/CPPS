#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:	type("WrongAnimal")
{
	std::cout << "WrongAnimal of type " << BOLDWHITE << this->type << RESET << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
	:	type(src.type)
{
	*this = src;
	std::cout << "WrongAnimal of type " << BOLDWHITE << this->type << RESET << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLDWHITE << "WrongAnimal " << RESET << " destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}


void WrongAnimal::makeSound() const
{
	std::cout << BOLDWHITE << this->type << RESET << " makes sound: " << BOLDWHITE << "random Wronganimal sound..." << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
