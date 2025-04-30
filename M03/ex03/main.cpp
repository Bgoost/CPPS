#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n--- Creating DiamondTrap ---\n" << std::endl;
	DiamondTrap diamonTrap("Mandarino");

	std::cout << "\n--- Showing Identity ---\n" << std::endl;
	diamonTrap.whoAmI();

	std::cout << "\n--- Attacking Sequence ---\n" << std::endl;
	diamonTrap.attack("some poor soul");
	std::cout << "Energy left: " << diamonTrap.getEnergyPoints() << std::endl;

	std::cout << "\n--- Taking Damage ---\n" << std::endl;
	diamonTrap.takeDamage(4);
	std::cout << "HP left: " << diamonTrap.getHitPoints() << std::endl;

	std::cout << "\n--- Repairing ---\n" << std::endl;
	diamonTrap.beRepaired(3);
	std::cout << "HP after repair: " << diamonTrap.getHitPoints() << std::endl;
	std::cout << "Energy left: " << diamonTrap.getEnergyPoints() << std::endl;

	std::cout << "\n--- Modifying Attack Damage ---\n" << std::endl;
	diamonTrap.setAttackDamage(42);
	diamonTrap.attack("another fool");

	std::cout << "\n--- Copy Constructor Check ---\n" << std::endl;
	DiamondTrap diamonTrap2(diamonTrap);
	diamonTrap2.whoAmI();

	std::cout << "\n--- Assignment Operator Check ---\n" << std::endl;
	DiamondTrap diamonTrap3;
	diamonTrap3 = diamonTrap;
	diamonTrap3.whoAmI();

	std::cout << "\n--- Destructor Check ---\n" << std::endl;
	return 0;
}



