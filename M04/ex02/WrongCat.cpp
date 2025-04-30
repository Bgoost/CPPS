#include "WrongCat.hpp"

WrongCat::WrongCat()
	:	WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << YELLOW << "WrongCat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " created" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
	:	WrongAnimal(src)
{
	this->type = src.type;
	std::cout << YELLOW << "WrongCat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " copy constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BOLDYELLOW << "WrongCat "<< RESET <<"destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << YELLOW << ITALIC << "🐱 Meow Meow 🐱" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << YELLOW << "WrongCat assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
