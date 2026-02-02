#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <sstream>
# include <cstring>

class	RPN
{
	public:
		RPN();		
		RPN(const RPN&);
		~RPN();

		RPN	&operator=(const RPN&);
		
		int calculate(const std::string& line);
		void clearStack();
		bool _showSteps;
	private:
		std::stack<float>	_stack;
};

#endif
