#include "ClapTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp" // make sure this points to your ClapTrap class definition

int main()
{
    ClapTrap clap1("Mandarino");
    ClapTrap clap2;

    std::cout << "\n--- Initial State ---\n";
    std::cout << clap1.getName() << ": " << clap1.getHitPoints() << " HP, "
              << clap1.getEnergyPoints() << " EP, "
              << clap1.getAttackDamage() << " AD\n";

    std::cout << clap2.getName() << ": " << clap2.getHitPoints() << " HP, "
              << clap2.getEnergyPoints() << " EP, "
              << clap2.getAttackDamage() << " AD\n";

    std::cout << "\n--- Setting Damage and Attacking ---\n";
    clap1.setAttackDamage(3);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());

    std::cout << "\n--- Healing THE CHOSEN ONE ---\n";
    clap2.beRepaired(5);

    std::cout << "\n--- Attacking Until Energy Runs Out ---\n";
    for (int i = 0; i < 10; i++)
        clap1.attack(clap2.getName());

    std::cout << "\n--- Trying to Repair With No Energy ---\n";
    clap1.beRepaired(2);

    std::cout << "\n--- Killing THE CHOSEN ONE ---\n";
    clap2.takeDamage(20);
    clap2.beRepaired(4);

    std::cout << "\n--- Final State ---\n";
	std::cout << clap1.getName() << ": " << clap1.getHitPoints() << " HP, "
			  << clap1.getEnergyPoints() << " EP, "
			  << clap1.getAttackDamage() << " AD\n";
	
	std::cout << clap2.getName() << ": " << clap2.getHitPoints() << " HP, "
			  << clap2.getEnergyPoints() << " EP, "
			  << clap2.getAttackDamage() << " AD\n";
    return (0);
}

