#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Colors.h"
class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &src);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
