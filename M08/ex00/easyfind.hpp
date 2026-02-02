#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "easyfind.h"

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        std::cout << "✅ Found " << value << "! Good instincts, soldier." << std::endl;
        //return the index of the found element
        return std::distance(container.begin(), it);
    } else {
        std::ostringstream oss;
        oss << value;
        throw std::runtime_error("❌ No sign of " + oss.str() + ".");
    }
}

#endif
