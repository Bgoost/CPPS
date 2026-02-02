#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

# include <fstream>
# include <iostream>
# include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        class UnableToCreateFileException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        void execute(const Bureaucrat &executor) const;
        std::string getTarget() const;
};



#endif
