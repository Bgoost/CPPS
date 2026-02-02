#include "Base.hpp"
#include "ABC.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << CYAN << "=== Identify real type ===" << RESET << std::endl;

	std::vector<Base*> objects;
	int rounds = 5;
	std::cout << BLUE << "\n[1] Generating " << rounds << " random objects...\n" << RESET;
	for (int i = 0; i < rounds; ++i)
		objects.push_back(generate());

	std::cout << GREEN << "\n[2] Identifying via pointer...\n" << RESET;
	for (size_t i = 0; i < objects.size(); ++i)
	{
		std::cout << YELLOW << "Object #" << i + 1 << ": " << RESET;
		identify(objects[i]);
	}

	std::cout << MAGENTA << "\n[3] Identifying via reference...\n" << RESET;
	for (size_t i = 0; i < objects.size(); ++i)
	{
		std::cout << YELLOW << "Object #" << i + 1 << ": " << RESET;
		identify(*objects[i]);
	}

	std::cout << RED << "\n[4] Testing edge case (NULL pointer)...\n" << RESET;
	std::cout << YELLOW << "Object is: " << RESET;
	identify((Base*)NULL);

	std::cout << RED << "\n[5] Forcing a bad dynamic_cast (wrong type / NULL pointer)...\n" << RESET;
	try {
		Base* bad = NULL;
		std::cout << YELLOW << "Object is: " << RESET;
		identify(*bad);
	} catch (...)
	{
		std::cout << RED << "Caught unexpected exception!" << RESET << std::endl;
	}

	std::cout << CYAN << "\n[6] Cleaning up...\n" << RESET;
	for (size_t i = 0; i < objects.size(); ++i)
		delete objects[i];
	objects.clear();

	return 0;
}




