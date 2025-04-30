#include "Cat.hpp"

Cat::Cat()
	:	Animal()
{
	this->type = "Cat";
	std::cout << YELLOW << "Cat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " created" << RESET << std::endl;
}

Cat::Cat(const Cat &src)
	:	Animal(src)
{
	this->type = src.type;
	std::cout << YELLOW << "Cat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " copy constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << BOLDYELLOW << "Cat "<< RESET <<"destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << YELLOW << ITALIC << "🐱 Meow Meow 🐱" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << YELLOW << "Cat assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
