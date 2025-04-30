#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void wrongAnimalMain(void)
{
	WrongAnimal *one = new WrongAnimal();
	WrongAnimal *two = new WrongCat();

	one->makeSound();
	two->makeSound();

	delete one;
	delete two;
}

int main(void)
{
	Animal *animals[4];

	for (int i = 0; i < 2; i++)
	{
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i + 1 << " type: ";
		std::cout << BOLDWHITE << animals[i]->getType() << RESET << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	std::cout << std::endl;
	wrongAnimalMain();
	std::cout << std::endl;
	return (0);
}
