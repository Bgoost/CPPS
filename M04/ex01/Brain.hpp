#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Colors.h"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();
		Brain &operator=(const Brain &rhs);

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
		void showIdeas() const;
};


#endif

