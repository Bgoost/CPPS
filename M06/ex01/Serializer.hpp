#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>
#include "Colors.h"

typedef unsigned long uintptr_t;

typedef struct s_data
{
    std::string text;
    int number;
} Data;


class Serializer 
{
    private:
        Serializer();

    public:
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif