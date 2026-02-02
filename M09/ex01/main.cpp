#include "RPN.hpp"

int	main(int argc, char** args)
{
	if (argc != 2)
	{
		std::cout << "\033[31mError: invalid number of arguments\033[0m" << std::endl;
		std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (-1);
	}
	if (args[1] && !args[1][0])
	{
		std::cerr << "\033[31mError: empty expression\033[0m\n";
		return (1);
	}

	RPN calculator;
	// calculator._showSteps = true;
	
	calculator.calculate(args[1]);

    // std::string line1 = "8 9 * 9 - 9 - 9 - 4 - 1 +"; // 42
    // std::string line2 = "7 7 * 7 -"; // 42
    // std::string line3 = "1 2 * 2 / 2 * 2 4 - +"; // 0
    // std::string line4 = "1 2 - - "; // Invalid structure
    // std::string line5 = "9 0 /"; // Division by zero
	// std::cout << "\n--- Calculations ---" << std::endl;
	// calculator.clearStack();
	// calculator.calculate(line1);
	// std::cout << "-----------------------------" << std::endl;
	// calculator.clearStack();
	// calculator.calculate(line2);
	// std::cout << "-----------------------------" << std::endl;
	// calculator.clearStack();
	// calculator.calculate(line3);
	// std::cout << "-----------------------------" << std::endl;
	// calculator.clearStack();
	// calculator.calculate(line4);
	// std::cout << "-----------------------------" << std::endl;
	// calculator.clearStack();
	// calculator.calculate(line5);

    return 0;
}
