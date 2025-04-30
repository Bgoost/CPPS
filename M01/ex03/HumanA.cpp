#include "HumanA.hpp"
#include <stdlib.h>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    // std::cout << GREEN << "HumanA named \"" << name << "\" created by GOD" << RESET << std::endl;
}

HumanA::~HumanA()
{
    // std::cout << "HumanA must" << BOLDRED << " 𝖉𝖎𝖊." << RESET << " Bye: "<< name << " 😇" << std::endl;
}

void HumanA::attack(void) const
{
    int len = this->weapon.getType().length();
    int color = 1;

    std::cout << this->name << " attacks with their ";
    for (int i = 0; i < len; i++)
    {
        std::cout << RESET;
        if (color)
        {
            std::cout << MAGENTA;
            color = 0;
        }
        else
        {
            std::cout << CYAN;
            color = 1;
        }
        std::cout << this->weapon.getType()[i];
    }
    std::cout << std::endl;
    std::cout << RESET;
}