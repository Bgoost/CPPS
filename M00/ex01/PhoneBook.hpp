#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "colors.h"
# include <iostream>
# include <string>
# include <cstdlib>

class PhoneBook
{
    private:
        Contact contact_arr[8];
        int len;
        int index;


    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);
        void display_contact(int i);
        void display_all_contacts();
        void print_str(std::string str, int print_pretty);
        
        Contact *get_contact_arr();
        int get_len();
        int get_index();
        int check_valid_index(const std::string index);

    

} ;

#endif