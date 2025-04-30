#ifndef USERINTERFACE_HPP
# define USERINTERFACE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "PhoneBook.hpp"

// class PhoneBook;

class UserInterface
{
    private:
        PhoneBook phonebook;
        std::string input;
        int error;
        // static bool is_alpha(const std::string &str);
        // static bool is_num(const std::string &str);
        // static bool is_alnum(const std::string &str);
        // static bool is_empty(const std::string &str);
    public:
        UserInterface();
        ~UserInterface();
        void manager();
        void ask_user_contact();
        void search_contact();
        // bool is_num(const std::string str);
        std::string ask_user_prompt(std::string prompt, bool (*f)(const std::string &));
        std::string prompt();
        std::string get_input();
};

#endif