#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include "iter.h"

template <typename T>
void battle(T &length)
{
	for(int i = 0; i < 4; ++i)
	{
		if(length[i] > 100)
			length[i] = 100;
		if(length[i] < -100)
			length[i] = -20;
	}
    double attack   = length[0] + length[1] * 0.5;
    double defense  = length[2] + length[3] * 0.3;
    double damage   = attack - defense;

    std::cout << "Battle outcome: ";
    if (damage > 0)
        std::cout << GREEN << "Player deals " << damage << " damage!" << RESET << std::endl;
    else
        std::cout << RED << "Player fails to hurt the enemy." << RESET << std::endl;
}


template <typename T>
void stats(T &length)
{
	
	std::string stat_str[4] = {"health     ", "energy     ", "sanity     ", "willpower  "};
	int stats = 4;
	double lower = 0;

	for(int i = 0; i < stats; ++i)
	{
		if(length[i] > 100)
		{
			length[i] = 100;
			std::cout << RED << "Stat is capped at 100." << RESET << std::endl;
		}
		if(length[i] <= -100)
		{
			length[i] = -20;
			std::cout << RED << "Stat is capped at -20." << RESET << std::endl;
		}
		if(length[i] < lower)
			lower = length[i];
	}
	std::cout << MAGENTA << "┌─────┐\t" << RESET;
	std::cout << "Player stats:" << std::endl;
	for (int i = 0; i < stats; ++i)
	{
		switch (i)
		{
			case 0: std::cout << MAGENTA << "│  O  │\t" << RESET; break;
			case 1: std::cout << MAGENTA << "│ ~|~ │\t" << RESET; break;
			case 2: std::cout << MAGENTA << "│ / \\ │\t" << RESET; break;
			case 3: std::cout << MAGENTA << "└─────┘\t" << RESET; break;
			default: break;
		}
		if (length[i] >= 0)
		{
			std::cout << stat_str[i];
			if(lower < 0)
			{
				for(int j = 0; j < -lower; ++j)
					std::cout << RED << " ";
			}
			std::cout << YELLOW << "|" << GREEN;
			for (int j = 0; j < length[i]; ++j)
			{
				std::cout << GREEN << "■";
			}
		}
		else
		{
			std::cout << stat_str[i];
			if(lower < 0)
			{
				for(int j = 0; j < -lower + length[i]; ++j)
					std::cout << " ";
			}
			for (int j = 0; j < -length[i]; ++j)
				std::cout << RED << "■";
			std::cout << YELLOW << "|" << RESET;
		}
		std::cout << RESET << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}
template <typename T>
void iter(const T* array, size_t length, void (*func)(const T&))
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}


template <typename T>
void print(T& element)
{
	std::cout << element << std::endl;
}

#endif
