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

void brainMain(void)
{
	Dog *dog = new Dog();

	dog->getBrain()->setIdea(69, "sheesh");
	dog->getBrain()->setIdea(-1, "Invalid?");
	dog->getBrain()->setIdea(5, "Funny number");
	std::cout << std::endl;

	dog->getBrain()->showIdeas();
	std::cout << std::endl;

	std::cout << dog->getBrain()->getIdea(99) << std::endl;

	delete dog;
}

void deepCopyMain(void)
{
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat(*cat1);

	std::cout << "Cat1 brain idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 brain idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
	cat2->getBrain()->setIdea(0, "hELOOOO IM A New idea, super duper cool");
	delete cat1;

	std::cout << "Cat2 brain idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
	delete cat2;
}

int main(void)
{
	int arrayNum = 100;
	Animal				*animalArray[arrayNum];
	int		i;

	i = 0;
	std::cout << "<-- -- Animal Brain Main -- -->" << std::endl;
	while (i < arrayNum / 2)
	{
		animalArray[i] = new Dog;
		std::cout << std::endl;
		i++;
	}
	while (i < arrayNum)
	{
		animalArray[i] = new Cat;
		std::cout << std::endl;
		i++;
	}
	i = 0;
	while (i < arrayNum)
	{
		delete animalArray[i];
		std::cout << std::endl;
		i++;
	}
	std::cout << "<-- -- Deep Copy Main -- -->" << std::endl;
	deepCopyMain();
	std::cout << std::endl;
	std::cout << "<-- -- Brain Ideas Main -- -->" << std::endl;
	brainMain();
	std::cout << std::endl;
	return (0);
}
