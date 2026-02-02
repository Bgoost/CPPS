#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <stdlib.h>
#include <complex>
#include <iomanip>
#include <string>
#include "array.h"

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		~Array(void);

		Array&			operator=(const Array &other);
		T&				operator[](int index) const;

		unsigned int	size(void) const;
};

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n) {
	if(n > 1000)
		throw std::length_error("Array size too large");
	else if (n > 0)
		_array = new T[n];
	else
		_array = NULL;
}

template <typename T>
Array<T>::Array(const Array &other) {
	_size = other._size;

    if (_size > 0)
    {
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    else
        _array = NULL;
}

template <typename T>
Array<T>::~Array(void) {
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		if (_array)
			delete[] _array;

		_size = other._size;
		if(_size > 0)
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= static_cast<int>(_size))
		throw std::out_of_range("Array index out of bounds");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

#endif
