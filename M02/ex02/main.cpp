#include "Fixed.hpp"
void arithmetic_tests() {
    Fixed a(6.2f);
    Fixed const b( a * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;
}

void comparison_tests() {
    Fixed a(-2);
    Fixed b(2);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= c: " << (a >= b) << std::endl;
    std::cout << "a <= d: " << (a <= b) << std::endl;
    std::cout << "a == c: " << (a == b) << std::endl;
    std::cout << "a != d: " << (a != b) << std::endl;
}

void increment_decrement_tests() {
    Fixed a(5.05f);
    
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    Fixed b(5.05f);
    std::cout << "b: " << b << std::endl;
    std::cout << "--b: " << --b << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "b: " << b << std::endl;
}

void min_max_tests() {
    Fixed a(5.05f);
    Fixed b(2.0f);
    Fixed const c(5.05f);
    Fixed const d(2.0f);

    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
    std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
    std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;
}

void all_tests() {
    std::cout << "---- Arithmetic Tests:" << std::endl;
    arithmetic_tests();
    std::cout << "---- Comparison Tests:" << std::endl;
    comparison_tests();
    std::cout << "---- Increment/Decrement Tests:" << std::endl;
    increment_decrement_tests();
    std::cout << "---- Min/Max Tests:" << std::endl;
    min_max_tests();
}

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    all_tests();
    return 0;
}

