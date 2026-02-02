#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {*this = other;}
ScalarConverter::~ScalarConverter() {}

void textUndefined()
{
	std::cout << "┌───────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "│ Please, provide a valid input. Example of inputs:     │" << std::endl;
	std::cout << "├─────────┬─────────────────────────────────────────────┤" << std::endl;
	std::cout << "│ Char\t  │'c', 'a'\t\t\t\t\t│" << std::endl;
	std::cout << "│ Int\t  │ 0, -42, 42\t\t\t\t\t│" << std::endl;
	std::cout << "│ Float\t  │ 0.0f, -4.2f, 4.2f\t\t\t\t│" << std::endl;
	std::cout << "│ Double  │ 0.0, -4.2, 4.2\t\t\t\t│" << std::endl;
	std::cout << "│ Literal │ +inf, -inf, nan, -inff, +inff, nanf\t\t│" << std::endl;
	std::cout << "└─────────┴─────────────────────────────────────────────┘" << std::endl;
}

bool isInvalid(const std::string &input)
{
	size_t i = 0;

	if (input.empty())
		return false;
	if (input[0] == '-' || input[0] == '+')
		i += 1;
	for(; i < input.length(); ++i)
	{
		if(!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && ((input[i] != 'e' && input[i] != 'E') && (input[i] != '+' && input[i] != '-')))
			return true;
	}
	return false;
}

int isChar(const std::string &input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return 1;
	return 0;
}

int isLiteral(const std::string &input)
{
	if (input == "nan" || input == "-inf" || input == "+inf"
		|| input == "nanf" || input == "-inff" || input == "+inff")
		return 1;
	return 0;
}

bool isInt(const std::string &input)
{
	char *end;

    std::strtol(input.c_str(), &end, 10);
	return(*end == '\0' && (input[0] != ' ' || input[0] != ' '));
}

bool	isFloat(const std::string &input)
{
	char *end;

	std::strtof(input.c_str(), &end);
	std::strtof(input.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0' && (input[0] != ' ' || input[0] != ' '));
}

bool	isDouble(const std::string &input)
{
	char *end;

	std::strtod(input.c_str(), &end);
	return (*end == '\0' && input[input.length() - 1] != '.' && (input[0] != ' ' || input[0] != ' '));
}

void charConv(const std::string &input, t_type &type)
{
	char c = input[0];

	if(type == CHAR)
		std::cout << "Char:\t'" << static_cast<char>(c) << "'\n";
	else if (type == LITERAL)
		std::cout << "Char:\t"<< RED <<"impossible\n"<< RESET;
	else
	{
		double num = 0;
		if(type == INT)
			num = std::atoi(input.c_str());
		else
			num = std::atof(input.c_str());
		if (num >= 0 && num <= 255 && std::isprint(num))
			std::cout << "Char:\t'" << static_cast<char>(num) << "'\n";
		else
			std::cout << "Char:\t"<< YELLOW <<"Non displayable\n"<< RESET;
	}
}

bool isSafeInt(const std::string &input)
{
	long int	res;

	if (input.length() > 11)
		return (false);
	res = std::atol(input.c_str());
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	return (true);
}

void intConv(const std::string &input, t_type &type)
{
	if(type == CHAR)
	{
		int num = static_cast<char>(input[0]);
		std::cout << "Int:\t" << static_cast<int>(num) << "\n";
	}
	else if (type  != LITERAL && isSafeInt(input))
		std::cout << "Int:\t" << std::atoi(input.c_str()) << "\n";
	else
		std::cout << "Int:\t"<< RED <<"impossible\n"<< RESET;
}

bool isSafeFloat(const std::string &input)
{
	double	res;

	res = std::atof(input.c_str());
	if (res > FLT_MAX || res < -FLT_MAX)
		return (false);
	return (true);
}

void floatConv(const std::string &input, t_type &type)
{
	//Not sure if should be done here
	// std::cout.setf(std::ios::fixed);
	// std::cout.precision(1);
	if (type == LITERAL || (isSafeFloat(input) && type != INT && type != CHAR))
	{
		std::cout << "Float:\t" << static_cast<float>(std::atof(input.c_str())) << "f\n";
		return ;
	}
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if(type == CHAR)
	{
		float num = static_cast<char>(input[0]);
		std::cout << "Float:\t" << static_cast<float>(num) << "f\n";
	}
	else if( type == INT && isSafeFloat(input))
	{

		std::cout << "Float:\t" << static_cast<float>(std::atof(input.c_str())) << "f\n";
	}
	else
		std::cout << "Float:\t"<< RED <<"impossible\n"<< RESET;
}

bool isSafeDouble(const std::string &input)
{
	long double	res;

	res = std::atof(input.c_str());
	if (res > DBL_MAX || res < -DBL_MAX)
		return (false);
	return (true);
}

void doubleConv(const std::string &input, t_type &type)
{
	if (type == LITERAL || (isSafeDouble(input) && type != INT && type != CHAR))
	{
		std::cout.setf(std::ios::scientific);
		std::cout << "Double:\t" << static_cast<double>(std::atof(input.c_str())) << "\n";
	}
	else if(type == CHAR)
	{
		double num = static_cast<char>(input[0]);
		std::cout << "Double:\t" << static_cast<double>(num) << "\n";
	}
	else if( type == INT && isSafeDouble(input))
	{
		std::cout.precision(1);
		std::cout << "Double:\t" << static_cast<double>(std::atof(input.c_str())) << "\n";
	}
	else
		std::cout << "Double:\t"<< RED <<"impossible\n"<< RESET;
}

t_type	ScalarConverter::getType(const std::string &input)
{
	if (isChar(input))
		return CHAR;
	else if (isLiteral(input))
		return LITERAL;
	else if (isInvalid(input))
		return UNDEFINED;
	else if (isInt(input))
		return INT;
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	return UNDEFINED;
}

void ScalarConverter::convert(const std::string &input)
{
	t_type type = getType(input);

	if( type == UNDEFINED)
		return(textUndefined(), void());
	charConv(input, type);
	intConv(input, type);
	floatConv(input, type);
	doubleConv(input, type);
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& var)
{
	if (this != &var)
		return (*this);
	return (*this);
}