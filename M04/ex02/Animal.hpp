#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Colors.h"
class A_Animal
{
	protected:
		std::string type;
	public:
		A_Animal();
		A_Animal(const A_Animal &src);
		virtual ~A_Animal();
		A_Animal &operator=(const A_Animal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
