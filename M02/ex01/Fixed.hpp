#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const float other);
    Fixed(const int other);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};
    std::ostream &operator<<(std::ostream &os, const Fixed &other);
