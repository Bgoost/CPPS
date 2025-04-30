#include "FragTrap.hpp"

FragTrap::FragTrap()
    :   ClapTrap("Brainrot_fragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << YELLOW << "FragTrap named " << BOLDYELLOW << getName() 
              << RESET << YELLOW << " created by god, he's the friendly one!" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
    :   ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << YELLOW << "FragTrap named " << BOLDYELLOW << getName() 
              << RESET << YELLOW << " created by god, he's the friendly one!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    :   ClapTrap(other)
{
    *this = other;
    std::cout << YELLOW << "FragTrap named " << BOLDYELLOW << getName() << RESET << YELLOW << " copy constructed!" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap must" << BOLDRED << " 𝖉𝖎𝖊." << RESET << " Bye: "<< getName() << " 😇" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << YELLOW << getName() << " is asking for a high five ✋ (Don't let him hanging)" << RESET << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "FragTrap " << BOLDYELLOW << getName() << RESET << " attacks " << ITALIC << YELLOW << target << RESET << ", causing " << attackDamage << " points of damage! He isn't that friendly after all" << std::endl;
        energyPoints--;
        if(energyPoints <= 0)
            std::cout << ITALIC << BOLDYELLOW << getName() << ": I-im rrunningg out of e-energʸʸ..." << RESET << std::endl;
    }
    else if (energyPoints <= 0)
        std::cout << "FragTrap " << BOLDYELLOW << getName() << RESET << " tried to attack but has no energy left to attack" << std::endl;
    else
        std::cout << "FragTrap " << BOLDYELLOW << getName() << RESET << " tried to attack but is already dead" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}