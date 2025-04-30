#include "Zombie.hpp"

Zombie* zombieHorde( int num, std::string name )
{
    if(num <= 0 || num > 100000)
    {
        std::cout << "Invalid number of zombies, try a number between 1 and 100000" << std::endl;
        return (NULL);
    }
    Zombie* horde = new Zombie[num];
    if(!horde)
        return (NULL);
    for (int i = 0; i < num; i++)
        horde[i].setName(name);
    return (horde);
}