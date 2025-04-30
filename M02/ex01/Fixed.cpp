#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const float other)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue =  roundf((float)other * (1 << _fractionalBits));
}
Fixed::Fixed(const int other)
{
    std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = other << _fractionalBits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		_fixedPointValue = other.getRawBits();
	}
	return(*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	// os << "Insertion operator called" << std::endl;
	os << other.toFloat();
	return(os);
}

float Fixed::toFloat() const
{
	// std::cout << "toFloat member function called" << std::endl;
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
	if (_fixedPointValue >= 0)
		return _fixedPointValue >> _fractionalBits;
	else
		return -((-_fixedPointValue) >> _fractionalBits);
}

int Fixed::getRawBits() const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}
