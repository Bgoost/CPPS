#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
    // std::cout << GREEN << "HumanB named \"" << name << "\" created by GOD" << RESET << std::endl;
}

HumanB::~HumanB()
{
    // std::cout << "HumanB must" << BOLDRED << " 𝖉𝖎𝖊." << RESET << " Bye: "<< name << " 😇" << std::endl;
}

void HumanB::attack(void) const
{
    
    if (this->weapon)
    {
        int len = this->weapon->getType().length();
        int color = 1;
        std::cout << name << " attacks with their ";
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
            std::cout << this->weapon->getType()[i];
        }
        std::cout << std::endl;
        std::cout << RESET;
    }
    else
        std::cout << this->name << " tried to attack has no weapon to attack with 😭😭 (skill issue)" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}