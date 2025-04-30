#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "ClapTrap.h"
#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int energyPoints;
		int hitPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string name);
		std::string getName() const;
		void setAttackDamage(unsigned int amount);
		unsigned int getAttackDamage() const;
		int getEnergyPoints() const;
		int getHitPoints() const;
		ClapTrap &operator=(const ClapTrap &other);
} ;

#endif