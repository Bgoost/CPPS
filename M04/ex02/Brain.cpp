#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
	std::cout << GREEN <<  "🧠 Brain created 🧠" << RESET << std::endl;

	for (int i = 0; i < 100; i++)
	{
		std::ostringstream oss;
		oss << "I am the number " << i << " brain idea";
		this->ideas[i] = oss.str();
	}

}

Brain::Brain(const Brain &src)
{
	std::cout << GREEN << "🧠 Brain copy constructor called 🧠" << RESET << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return (std::cout << "Invalid index, not getting any idea" << std::endl, std::string());
	return (this->ideas[index]);
}

void Brain::showIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Idea [" << i << "]: " << this->ideas[i] << std::endl;
	}
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index, not setting any idea" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

