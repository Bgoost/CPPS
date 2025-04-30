#include "Zombie.hpp"

Zombie::Zombie(): name("")
{
    std::cout << GREEN << "Zombie created by god" << RESET << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie must" << BOLDRED << " 𝖉𝖎𝖊." << RESET << " Bye: "<< name << " 😇" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << name << ": " << CYAN << "B" 
    << MAGENTA << "r" 
    << CYAN << "a" 
    << MAGENTA << "i"<< CYAN <<"i"<< MAGENTA <<"i" << CYAN <<"i"<< MAGENTA <<"i"<< CYAN <<"i"<< MAGENTA <<"i" 
    << CYAN << "n"<< MAGENTA <<"n"<< CYAN <<"n" 
    << MAGENTA << "z"<< CYAN <<"z"<< MAGENTA <<"z"<< CYAN <<"Z" 
    << MAGENTA << "."<< CYAN <<"."<< BLUE <<"." << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}