#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include "colors.h"

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        const std::string &getType(void) const;
        void setType(std::string type);
};

#endif