#include "Cat.hpp"

Cat::Cat()
	:	Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << YELLOW << "Cat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " created" << RESET << std::endl;
}

Cat::Cat(const Cat &src)
	:	Animal(src)
{
	this->type = src.type;
	this->brain = new Brain();
	std::cout << YELLOW << "Cat of type " << BOLDYELLOW << this->type << RESET << YELLOW << " copy constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << BOLDYELLOW << "Cat "<< RESET <<"destructor called " << RED << "(RIP 🪦 )" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << YELLOW << ITALIC << "🐱 Meow Meow 🐱" << RESET << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << YELLOW << "Cat assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*(this->brain) = *other.getBrain();
	}
	return (*this);
}
