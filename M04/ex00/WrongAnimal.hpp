#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Colors.h"
class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &rhs);

		void makeSound() const;
		std::string getType() const;
};

#endif
