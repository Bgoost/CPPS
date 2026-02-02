#include "Base.hpp"
#include "ABC.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }
	int r = std::rand() % 3;
	switch (r)
	{
		case 0:
			std::cout << "Creating instance of " << CYAN << "A" << RESET << std::endl;
			return new A;
		case 1:
			std::cout << "Creating instance of " << CYAN << "B" << RESET << std::endl;
			return new B;
		case 2:
			std::cout << "Creating instance of " << CYAN << "C" << RESET << std::endl;
			return new C;
		default:
			break;
	}
	return NULL;
}

void identify(Base *p)
{
	if(!p)
	{
		std::cout << "Pointer is NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "Object is of type " << CYAN << "A" << RESET << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Object is of type " << CYAN << "B" << RESET << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Object is of type " << CYAN << "C" << RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << CYAN << "A" << RESET << std::endl;
		return ;
	} catch (std::exception &e) 
	{
		std::cout << "Caught " << MAGENTA << "bad cast" << RESET << ": object is " << RED << "NOT" << RESET << " an " << CYAN << "A" << RESET << std::endl;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << CYAN << "\t   B" << RESET << std::endl;
		return ;
	} catch (std::exception &e)
	{
		std::cout << "\t   Caught " << MAGENTA << "bad cast" << RESET << ": object is " << RED << "NOT" << RESET << " a  "<< CYAN << "B" << RESET << std::endl;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << CYAN << "\t   C" << RESET << std::endl;
		return ;
	} catch (std::exception &e)
	{
		std::cout << "\t   Caught " << MAGENTA << "bad cast" << RESET << ": object is " << RED << "NOT" << RESET << " a  "<< CYAN << "C" << RESET << std::endl;
	}
}

