#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << GREEN << "[DEBUG]" << RESET << std::endl;
    std::cout << "Wrote a single line of code. Everything looks fine. Feeling like a 10x developer. Time for a coffee break." << std::endl;
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << CYAN << "[INFO]" << RESET << std::endl;
    std::cout << "Ran the code. Compilation successful. No errors. Confidence at an all-time high. Might update my LinkedIn to 'Software Architect'." << std::endl;
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << YELLOW << "[WARNING]" << RESET << std::endl;
    std::cout << "Program executed, but output is… unexpected. The code technically works, just not in the way that anyone would ever want." << std::endl;
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << RED << "[ERROR]" << RESET << std::endl;
    std::cout << "Tried to fix the bug. Created three new ones. The debugger is just laughing at me now. Considering a career in goat farming." << std::endl;
}

void corrupted()
{
    std::cout << BOLDRED << "[CₒRᴿUₚTᴱD]" << RESET << std::endl;
    std::cout << "Stack Overflow copy-paste attempt failed. The code now speaks an unknown dialect of chaos. Computer refuses to cooperate. I am one semicolon away from total collapse." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
    std::string levels[4] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    corrupted();
}

