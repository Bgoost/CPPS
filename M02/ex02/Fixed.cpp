#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const float other)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointValue =  roundf((float)other * (1 << _fractionalBits));
}
Fixed::Fixed(const int other)
{
    // std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = other << _fractionalBits;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		_fixedPointValue = other.getRawBits();
	}
	return(*this);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed tmp;

	// std::cout << "Addition operator called" << std::endl;
	tmp.setRawBits(_fixedPointValue + other.getRawBits());
	// _fixedPointValue += other.getRawBits();
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed tmp;
	// std::cout << "Subtraction operator called" << std::endl;
	tmp.setRawBits(_fixedPointValue - other.getRawBits());
	return (*this);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed tmp;
	long tmpValue;

	// std::cout << "Multiplication operator called" << std::endl;
	tmpValue = _fixedPointValue;
	tmpValue *= other.getRawBits();
	tmpValue = tmpValue >> _fractionalBits;
	tmp.setRawBits(tmpValue);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed tmp;
	long tmpValue;
	// std::cout << "Division operator called" << std::endl;
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (*this);
	}
	tmpValue = _fixedPointValue;
	tmpValue = tmpValue << _fractionalBits;
	tmpValue /= other.getRawBits();
	tmp.setRawBits(tmpValue);
	return (tmp);
}

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	// os << "Insertion operator called" << std::endl;
	os << other.toFloat();
	return(os);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed &Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_fixedPointValue++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_fixedPointValue--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	// std::cout << "Min function called" << std::endl;
	if(a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	// std::cout << "Min function called" << std::endl;
	if(a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	// std::cout << "Min function called" << std::endl;
	if(a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	// std::cout << "Min function called" << std::endl;
	if(a > b)
		return (a);
	else
		return (b);
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
