#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    :   ClapTrap("Brainrot_scavTrap")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << MAGENTA << "ScavTrap named " << BOLDMAGENTA << getName()
              << RESET << MAGENTA << " created by god" << RESET << std::endl;

}

ScavTrap::ScavTrap(std::string name)
    :   ClapTrap(name)
{
    std::cout << "ClapTrap name initialized to: " << name << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << MAGENTA << "ScavTrap named " << BOLDMAGENTA << getName()
              << RESET << MAGENTA << " created by god" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    :   ClapTrap(other)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << MAGENTA << "ScavTrap named " << BOLDMAGENTA << getName()
              << RESET << MAGENTA << " copy constructed!" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap must" << BOLDRED << " 𝖉𝖎𝖊." << RESET
              << " Bye: "<< getName() << " 😇" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << MAGENTA << getName() << " is now in guard gate mode" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "The fearless ScavTrap " << BOLDMAGENTA << getName() << RESET << " attacks " << MAGENTA << ITALIC << target << RESET << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
        if(energyPoints <= 0)
            std::cout << ITALIC << YELLOW << getName() << ": I-im rrunningg out of e-energʸʸ..." << RESET << std::endl;
    }
    else if (energyPoints <= 0)
        std::cout << "ScavTrap " << MAGENTA << getName() << RESET << " tried to attack but has no energy left to attack" << std::endl;
    else
        std::cout << "ScavTrap " << MAGENTA << getName() << RESET << " tried to attack but is already dead" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}