#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <stdlib.h>
#include <limits>
#include <climits>
#include <cfloat>
# include <iostream>
#include "Colors.h"

enum t_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN,
	LITERAL,
	UNDEFINED
};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& other);
		~ScalarConverter();

		ScalarConverter&	operator=( const ScalarConverter& );

		static void		convert(const std::string &input);
		static t_type	getType(const std::string &input);
		static void		convertToChar(const std::string &input, t_type &type);
		static void		convertToInt(const std::string &input, t_type &type);
		static void		convertToFloat(const std::string &input, t_type &type);
		static void		convertToDouble(const std::string &input, t_type &type);
} ;

#endif
