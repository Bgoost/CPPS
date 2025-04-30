#include "Weapon.hpp"

Weapon::Weapon(void): type("pretty face")
{

}

Weapon::Weapon(std::string type) : type(type)
{
    this->type = type;
}

Weapon::~Weapon()
{

    int len = type.length();
    int color = 1;
    std::cout << "Weapon ";
    for (int i = 0; i < len; i++)
    {
        std::cout << RESET;
        if (color)
        {
            std::cout << MAGENTA;
            color = 0;
        }
        else
        {
            std::cout << CYAN;
            color = 1;
        }
        std::cout << type[i];
    }
    std::cout << RESET;

    std::cout <<" destroyed" << std::endl;
}

const std::string &Weapon::getType(void) const
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}