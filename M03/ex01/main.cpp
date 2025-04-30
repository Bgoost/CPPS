#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ScavTrap scav1("Shiny");
    ScavTrap scav2("Mandarino");
	ClapTrap clap1("Natalia");



    std::cout << "\n--- Initial State ---\n";
    std::cout << scav1.getName() << ": " << scav1.getHitPoints() << " HP, "
              << scav1.getEnergyPoints() << " EP, "
              << scav1.getAttackDamage() << " AD\n";
    std::cout << scav2.getName() << ": " << scav2.getHitPoints() << " HP, "
              << scav2.getEnergyPoints() << " EP, "
              << scav2.getAttackDamage() << " AD\n";

    std::cout << "\n--- ScavTrap Interactions ---\n";
	clap1.attack(scav1.getName());
    clap1.setAttackDamage(5);
	scav1.takeDamage(clap1.getAttackDamage());
	for(int i = 0; i < 5; i++)
	{
		scav1.attack(scav2.getName());
		scav2.takeDamage(scav1.getAttackDamage());
	}
	std::cout << "\n--- ScavTrap Guard Gate ---\n";
    scav1.guardGate();
    std::cout << "\n--- Both ScavTraps Perform Repairs ---\n";
    scav1.beRepaired(5);
    scav2.beRepaired(10);

    std::cout << "\n--- Final State ---\n";
    std::cout << scav1.getName() << ": " << scav1.getHitPoints() << " HP, "
              << scav1.getEnergyPoints() << " EP, "
              << scav1.getAttackDamage() << " AD\n";
    std::cout << scav2.getName() << ": " << scav2.getHitPoints() << " HP, "
              << scav2.getEnergyPoints() << " EP, "
              << scav2.getAttackDamage() << " AD\n";


    return 0;
}


