#include "Harlfilter.hpp"

std::string string_lowercase(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harlfilter harlfilter;
    std::string lower = string_lowercase(argv[1]);
    harlfilter.filter(argv[1]);
    return 0;
}