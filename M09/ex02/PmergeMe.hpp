#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <climits>

class PmergeMe {
private:
	std::vector<int> vec;
	std::deque<int> deq;

	void fordJohnsonSortVector(std::vector<int>& arr);
	void fordJohnsonSortDeque(std::deque<int>& arr);
	std::vector<size_t> generateJacobsthalIndices(size_t n) const;

	template <typename Container>
	void binaryInsert(Container& sorted, typename Container::value_type val);
	template <typename Container>
	void printContainer(const Container &c) const;


public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void loadData(char **argv);
	void process();
};

template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, typename Container::value_type val) {
	typename Container::iterator low = sorted.begin();
	typename Container::iterator high = sorted.end();

	while (low < high) {
		typename Container::iterator mid = low + (high - low) / 2;
		if (*mid < val)
			low = mid + 1;
		else
			high = mid;
	}
	sorted.insert(low, val);
}

template <typename Container>
void PmergeMe::printContainer(const Container &c) const
{
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator end = c.end();
    while (it != end) {
        std::cout << *it;
        ++it;
        if (it != end)
            std::cout << " ";
    }
    std::cout << std::endl;
}

#endif
