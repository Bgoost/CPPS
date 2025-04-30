#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);

		void makeSound() const;
		Brain *getBrain() const;
};

#endif
