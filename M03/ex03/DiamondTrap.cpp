#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    :   ClapTrap("DiamondTrap_clap_name"),
	    name("DiamondTrap"),
        clapTrapName(ClapTrap::name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
    std::cout << CYAN << "DiamondTrap named " << BOLDCYAN << name
            << RESET << CYAN << " created by god" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    :   ClapTrap(name + "_clap_name"),
	    name(name),
        clapTrapName(ClapTrap::name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
    std::cout << CYAN << "DiamondTrap named " << BOLDCYAN << name
            << RESET << CYAN << " created by god" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
    :   ClapTrap(other),
        FragTrap(other),
        ScavTrap(other),
        name(other.name),
        clapTrapName(other.clapTrapName)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
    std::cout << CYAN << "DiamondTrap named " << BOLDCYAN << other.name
			  << RESET << CYAN << " copy constructed" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << CYAN << "DiamondTrap" << RESET <<" must" << BOLDRED << " 𝖉𝖎𝖊." << RESET
			  << " Bye: "<< name << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << BOLDCYAN << name << RESET << std::endl;
    std::cout << "ClapTrap name: " << BOLDCYAN << clapTrapName << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
    }
    return (*this);
}
