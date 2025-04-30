#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie(std::string name);

int main()
{
    Zombie *zombie = newZombie("Mandarino");
    zombie->announce();
    delete (zombie);

    randomChump("Shiny");

    return (0);
}