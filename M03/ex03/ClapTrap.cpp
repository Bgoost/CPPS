#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	name("THE CHOSEN ONE"),
		energyPoints(10),
		hitPoints(10),
		attackDamage(0)
{
    std::cout << WHITE << "ClapTrap named " << BOLDWHITE << name 
			  << RESET << WHITE << " created by god" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:	name(name),
		energyPoints(10),
		hitPoints(10),
		attackDamage(0)
{
    std::cout << WHITE << "ClapTrap named " << BOLDWHITE << name
			  << RESET << WHITE << " created by god" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << WHITE << "ClapTrap named " << BOLDWHITE << other.name
			  << RESET << WHITE << " copy constructed" << RESET << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{	
    std::cout << "ClapTrap must" << BOLDRED << " 𝖉𝖎𝖊." << RESET
			  << " Bye: "<< name << " 😇" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " is dead and can't attack." << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << BOLDWHITE << name << RESET << " attacks " << ITALIC << WHITE
	          << target << RESET << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
	if (energyPoints == 0)
		std::cout << ITALIC << YELLOW << name << ": I-im rrunningg out of e-energʸʸ..." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if((int)amount < 0)
	{
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " tried to take damage but can't take negative damage" << std::endl;
		return ;
	}
	if(hitPoints > 0)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " recieved "<< amount <<" points of damage!" << std::endl;
		if (hitPoints <= 0)
			std::cout << ITALIC << YELLOW << name << ": Oh no, it's too late now, I'm bleeding to death..." << RESET << std::endl;
		if (hitPoints < 0)
			hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET <<" tried to take damage but is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if((int)amount < 0)
	{
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " can't be repaired with negative amount" << std::endl;
		return ;
	}
	if(energyPoints > 0 &&  hitPoints > 0)
	{
		hitPoints += amount;
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " is repairing itself" << std::endl;
		energyPoints--;
		if(energyPoints <= 0)
			std::cout << ITALIC << YELLOW << name << ": I-im rrunningg out of e-energʸʸ..." << RESET << std::endl;
	}
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " tried to repair itself but has no energy left to repair itself" << std::endl;
	else if (hitPoints <= 0)
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " tried to repair itself but is already dead" << std::endl;
	else
		std::cout << "ClapTrap " << BOLDWHITE << name << RESET << " tried to repair itself but is already at full health" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (name);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	if ((int)amount > 0)
		std::cout << "ClapTrap " << BOLDWHITE << this->name << RESET << " is setting attack damage to " << amount << std::endl;
	else
	{
		std::cout << "Attack Damage can't be negative, ClapTrap " << BOLDWHITE << this->name << RESET << " is setting attack damage to 0" << std::endl;
		amount = 0;
	}
	attackDamage = amount;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}

int ClapTrap::getEnergyPoints() const
{
	return (energyPoints);
}

int ClapTrap::getHitPoints() const
{
	return (hitPoints);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}
