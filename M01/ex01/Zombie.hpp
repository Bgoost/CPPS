#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include "colors.h"

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce(void) const;
        void setName(std::string name);
};

#endif