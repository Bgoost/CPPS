#include "Zombie.hpp"

Zombie* zombieHorde( int num, std::string name );

int main(void)
{
    //integer maximum value = 2147483647
    int num = 10;
    Zombie* horde = zombieHorde(num, "Zombie");
    if(!horde)
        return (-1);
    for (int i = 0; i < num; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}
