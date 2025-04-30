#include "UserInterface.hpp"

UserInterface::UserInterface()
{
    input = "";
    error = 0;
    // std::cout << "UserInterface created" << std::endl;
}

UserInterface::~UserInterface()
{
    // std::cout << "UserInterface destroyed" << std::endl;
}


void UserInterface::manager()
{
    phonebook.add_contact("a", "a", "a", "1", "1");
    phonebook.add_contact("b", "b", "b", "2", "2");
    phonebook.add_contact("c", "c", "c", "3", "3");
    phonebook.add_contact("d", "d", "d", "4", "4");
    phonebook.add_contact("e", "e", "e", "5", "5");
    phonebook.add_contact("f", "f", "f", "6", "6");
    phonebook.add_contact("g", "g", "g", "7", "7");
    phonebook.add_contact("h", "h", "h", "8", "8");
    while(1)
    {
        std::string input = prompt();
        if(error)
            return;
        if(input == "exit" || input == "EXIT")
            return;
        else if(input == "add" || input == "ADD")
            ask_user_contact();
        else if(input == "search" || input == "SEARCH")
            search_contact();
        else if (input.empty())
            std::cout << RED << "Can't input an empty string" << RESET << std::endl;
        else
            std::cout << RED << "Invalid command, try ADD, SEARCH or EXIT" << RESET << std::endl;
    }
}

std::string UserInterface::ask_user_prompt(std::string prompt, bool (*f)(const std::string &))
{
    std::string tmp;
    while (tmp.empty())
    {
        std::cout << prompt;
        tmp = get_input();
        if (tmp.empty())
            std::cout << RED << "Can't input an empty string" << RESET << std::endl;
        else if (f(tmp) == false)
        {
            std::cout << RED << "Invalid input" << RESET << std::endl;
            tmp.clear();
        }
    }
    return tmp;
}

bool is_alpha(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isalpha(str[i]))
            return false;
    }
    return true;
}

bool is_alnum(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isalnum(str[i]))
            return false;
    }
    return true;
}



bool is_num(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

bool is_empty(const std::string &str)
{
    if(str.empty())
        return false;
    return true;
}

void UserInterface::ask_user_contact()
{
    std::string tmp;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    tmp = ask_user_prompt("Enter first name: ", is_alpha);
    first_name = tmp;
    tmp = ask_user_prompt("Enter last name: ", is_alpha);
    last_name = tmp;
    tmp = ask_user_prompt("Enter nickname: ", is_alnum);
    nickname = tmp;
    tmp = ask_user_prompt("Enter phone number: ", is_num);
    phone_number = tmp;
    tmp = ask_user_prompt("Enter secret: ", is_empty);
    secret = tmp;

    phonebook.add_contact(first_name, last_name, nickname, phone_number, secret);
    std::cout << YELLOW << "Contact added" << RESET << std::endl;
}

void UserInterface::search_contact()
{
    if(phonebook.get_len() == 0)
    {
        std::cout << RED << "No contacts to search, try adding some with the command add | ADD" << RESET << std::endl;
        return;
    }
    std::cout << "Searching contact" << std::endl;
    phonebook.display_all_contacts();
    std::cout << "Enter contact index to reveal more info: ";
    std::string input = get_input();
    int index = phonebook.check_valid_index(input);
    while(index == -1)
    {
        std::cout << "Enter contact index to reveal more info: ";
        input = get_input();
        index = phonebook.check_valid_index(input);
    }
    std::cout << CYAN << "═════════════════════════════════════════════" << RESET << std::endl;
    phonebook.display_contact(index);
    std::cout << CYAN << "═════════════════════════════════════════════" << RESET << std::endl;
}

std::string UserInterface::prompt()
{
    std::cout << "Enter input: ";
    return get_input();
}

std::string UserInterface::get_input()
{
    if(!getline(std::cin, input))
    {
        std::cout << "Don't CTRL+D mf(my friend)" << std::endl;
        std::cout << RED << "Exiting now" << RESET << std::endl;
        exit(1);
        return "";
    }
    return input;
}
