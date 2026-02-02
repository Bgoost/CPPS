#include "RPN.hpp"

RPN::RPN() : _showSteps(false) {}

RPN::RPN(const RPN& var) : _showSteps(var._showSteps), _stack(var._stack) {}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& var)
{
	if (this != &var)
	{
		_showSteps = var._showSteps;
		_stack = var._stack;
	}
	return (*this);
}

bool isOperator(const std::string& token) {
	return token.length() == 1 && 
			(token[0] == '+' || token[0] == '-' || 
			token[0] == '*' || token[0] == '/');
}

bool isNumber(const std::string& token) {
	if (token.length() != 1) return false;

	return std::isdigit(static_cast<unsigned char>(token[0]));
}

void RPN::clearStack() {
	while (!_stack.empty()) {
		_stack.pop();
	}
}

int RPN::calculate(const std::string& line) {
	
	clearStack();
	std::stringstream ss(line);
	std::string token;
	
	while (ss >> token) {
		if (isNumber(token)) {
			_stack.push(token[0] - '0');
		} else if (isOperator(token)) {
			if (_stack.size() < 2) {
				clearStack();
				std::cout << "\033[31mError: not enough elements to make operation\033[0m" << std::endl;
				return -1;
			}

			float op2 = _stack.top();
			_stack.pop();
			float op1 = _stack.top();
			_stack.pop();

			float result = 0;
			char op = token[0];

			switch (op) {
				case '+': result = op1 + op2; break;
				case '-': result = op1 - op2; break;
				case '*': result = op1 * op2; break;
				case '/': 
					if (op2 == 0) {
						clearStack();
						std::cout << "\033[31mError: division by zero\033[0m" << std::endl;
						return -1;
					}
					result = op1 / op2; 
					break;
			}
			if (_showSteps)
				std::cout << op1 << " " << op << " " << op2 << " = " << result << std::endl;
			_stack.push(result);
		} else {
			std::cout << "\033[31mError: invalid token \"\033[0m" << token << "\".\nTokens must be numbers from 0 to 9 or operators (+, -, *, /)." << std::endl;
			clearStack();
			return -1;
		}
	}
	if (_stack.size() == 1) {
		std::cout << _stack.top() << std::endl;
		return 0;
	} else {
		clearStack();
		std::cout << "\033[31mError: too many elements / missing operation\033[0m" << std::endl;
		return -1;
	}
	return (0);
}