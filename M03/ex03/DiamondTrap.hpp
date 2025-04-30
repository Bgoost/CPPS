#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
        std::string clapTrapName;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();
        void whoAmI(void);
        void attack(const std::string &target);
        DiamondTrap &operator=(const DiamondTrap &other);
} ;

#endif