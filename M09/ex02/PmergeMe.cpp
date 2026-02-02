#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

void PmergeMe::loadData(char **argv) {
	for (int i = 1; argv[i]; ++i) {
		std::istringstream iss(argv[i]);
		long n;
		if (!(iss >> n) || n <= 0)
			throw std::runtime_error("Error");
		if (n > INT_MAX)
			throw std::runtime_error("Number too large");
		vec.push_back(static_cast<int>(n));
		deq.push_back(static_cast<int>(n));
	}
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) const {
	std::vector<size_t> seq;
	if (n == 0)
		return seq;

	size_t j1 = 1, j2 = 1;
	seq.push_back(1);
	while (true) {
		size_t next = j2 + 2 * j1;
		if (next > n)
			break;
		seq.push_back(next);
		j1 = j2;
		j2 = next;
	}

	std::vector<size_t> result;
	result.push_back(1);
	for (size_t i = 1; i < seq.size(); ++i) {
		for (size_t k = seq[i]; k > seq[i - 1]; --k) {
			if (k <= n)
				result.push_back(k);
		}
	}
	for (size_t k = n; k > seq.back(); --k)
		result.push_back(k);

	return result;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	std::vector<int> small, large;
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		small.push_back(arr[i]);
		large.push_back(arr[i + 1]);
	}
	if (n % 2 != 0)
		small.push_back(arr.back());

	fordJohnsonSortVector(large);

	std::vector<int> sorted = large;
	binaryInsert(sorted, small[0]);

	std::vector<size_t> order = generateJacobsthalIndices(small.size());
	for (size_t i = 1; i < order.size(); ++i)
		binaryInsert(sorted, small[order[i] - 1]);

	arr = sorted;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	std::deque<int> small, large;
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		small.push_back(arr[i]);
		large.push_back(arr[i + 1]);
	}
	if (n % 2 != 0)
		small.push_back(arr.back());

	fordJohnsonSortDeque(large);

	std::deque<int> sorted = large;
	binaryInsert(sorted, small[0]);

	std::vector<size_t> order = generateJacobsthalIndices(small.size());
	for (size_t i = 1; i < order.size(); ++i)
		binaryInsert(sorted, small[order[i] - 1]);

	arr = sorted;
}

void PmergeMe::process() {
	std::cout << " Before: ";
	printContainer(vec);

	clock_t startVec = clock();
	fordJohnsonSortVector(vec);
	clock_t endVec = clock();

	std::cout << " After: ";
	printContainer(vec);
	double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000; // microseconds

	std::cout << " Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vecTime << " ms\n";

	std::cout << "\033[34m<<--------------------------------------------------------------->>\033[0m"<< std::endl;
	std::cout << " Before: ";
	printContainer(deq);

	clock_t startDeq = clock();
	fordJohnsonSortDeque(deq);
	clock_t endDeq = clock();

	std::cout << " After: ";
	printContainer(deq);

	double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000;

	std::cout << " Time to process a range of " << deq.size()
			<< " elements with std::deque  : " << deqTime << " ms\n";
}
