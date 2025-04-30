#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Shiny");
    ScavTrap scav1("Mandarino");
	ClapTrap clap1("Natalia");

    std::cout << "\n--- Initial State ---\n";
    std::cout << frag1.getName() << ": " << frag1.getHitPoints() << " HP, "
              << frag1.getEnergyPoints() << " EP, "
              << frag1.getAttackDamage() << " AD\n";
    std::cout << scav1.getName() << ": " << scav1.getHitPoints() << " HP, "
              << scav1.getEnergyPoints() << " EP, "
              << scav1.getAttackDamage() << " AD\n";

    std::cout << "\n--- ScavTrap Interactions ---\n";
	clap1.attack(frag1.getName());
    clap1.setAttackDamage(5);
	frag1.takeDamage(clap1.getAttackDamage());
    scav1.attack(clap1.getName());
    clap1.takeDamage(scav1.getAttackDamage());
	for(int i = 0; i < 5; i++)
	{
		frag1.attack(scav1.getName());
		scav1.takeDamage(frag1.getAttackDamage());
	}
	std::cout << "\n--- ScavTrap Guard Gate ---\n";
    scav1.guardGate();

    std::cout << "\n--- Highfive!! ---\n";
    frag1.highFivesGuys();

    std::cout << "\n--- Both ScavTraps Perform Repairs ---\n";
    frag1.beRepaired(5);
    scav1.beRepaired(10);

    std::cout << "\n--- Final State ---\n";
    std::cout << frag1.getName() << ": " << frag1.getHitPoints() << " HP, "
              << frag1.getEnergyPoints() << " EP, "
              << frag1.getAttackDamage() << " AD\n";
    std::cout << scav1.getName() << ": " << scav1.getHitPoints() << " HP, "
              << scav1.getEnergyPoints() << " EP, "
              << scav1.getAttackDamage() << " AD\n";


    return 0;
}


