#include "iter.hpp"
#include <iostream>

int main()
{
	double player[][4] = {
		{-100, -100, -1211.0, -1110.0},
		{20.1, -111.0, 42.0, -2.0},
		{40.0, -2.0, 0.1, 50.23},
		{985.0, -2.0, 0.1, -222.23}
	};
	std::string words[] = {"The", "End"};

	::iter(player, 4, stats);
	::iter(player, 4, battle);
	::iter(words, 2, print);

	return 0;
}
