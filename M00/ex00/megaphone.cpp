/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:11:12 by crmanzan          #+#    #+#             */
/*   Updated: 2024/12/10 20:55:54 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDbACK NOISE *";
	else
	{
		i = 1;
		for(i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i];
			if((i + 1) < argc)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return(0);
}
