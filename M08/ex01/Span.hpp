#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include "Span.h"

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    template <typename InputIt>
    void addRange(InputIt begin, InputIt end);

    const std::vector<int>& getNumbers() const { return _numbers; }
    unsigned int getMaxSize() const { return _maxSize; }
    int shortestSpan() const;
    int longestSpan() const;
};

#include "Span.tpp"

#endif
