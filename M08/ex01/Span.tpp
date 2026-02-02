#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename InputIt>
void Span::addRange(InputIt begin, InputIt end) {
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::runtime_error("Not enough space in Span to add range");
	_numbers.insert(_numbers.end(), begin, end);
}

#endif
