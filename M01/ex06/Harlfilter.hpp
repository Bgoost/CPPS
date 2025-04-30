#ifndef HARLFILTER_H
#define HARLFILTER_H
#include <iostream>
#include "colors.h"

class Harlfilter
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harlfilter();
        ~Harlfilter();
        void filter( std::string level);
};
#endif