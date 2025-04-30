#include "Fixed.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    float f = argv[1] ? atof(argv[1]) : 0;
    Fixed a(f);

    std::cout << "a is " << a << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
}

// int main() {
//     Fixed a;
//     Fixed const b( 10 );
//     Fixed const c( -42.52f );
//     Fixed const d( b );

//     a = Fixed( 1234.4321f );


//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// }

