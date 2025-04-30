#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

//  stringREF = "Bye bye";
    std::cout << "Address in memory of the string: " << &str << std::endl;
    std::cout << "Address in memory of the string pointer: " << stringPTR << std::endl;
    std::cout << "Address in memory of the string reference: " << &stringREF << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "String pointer: " << *stringPTR << std::endl;
    std::cout << "String reference: " << stringREF << std::endl;

    return (0);
}
