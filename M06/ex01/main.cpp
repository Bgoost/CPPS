#include "Serializer.hpp"

std::string getRowColor(int row)
{
	switch (row % 3)
	{
		case 0:
			return BOLDCYAN;
		case 1:
			return BOLDYELLOW;
		case 2:
			return BOLDGREEN;
		default:
			return RESET;
	}
}

void	initData(Data &var, const std::string text, int number)
{
	var.text = text;
	var.number = number;
}

void printTableHeader() {
	std::cout << BOLDWHITE
			  << "╔═══════════════════╦════════════════╦══════════════╗\n"
			  << "║     Address       ║      Text      ║    Number    ║\n"
			  << "╠═══════════════════╬════════════════╬══════════════╣\n"
			  << RESET;
}

void printTableRow(const Data &d, int row) {
	std::string rowColor = getRowColor(row);

	std::cout << BOLDWHITE << "║ "
			  << rowColor << std::setw(17) << &d << BOLDWHITE
			  << " ║ " << rowColor << std::setw(14) << d.text << BOLDWHITE
			  << " ║ " << rowColor << std::setw(12) << d.number << BOLDWHITE
			  << " ║" << RESET << "\n";
}

void printTableFooter() {
	std::cout << BOLDWHITE
			  << "╚═══════════════════╩════════════════╩══════════════╝\n\n"
			  << RESET;
}

int main() {
	std::vector<Data*> originalPointers;
	std::vector<uintptr_t> storage;
	std::vector<uintptr_t> validSerialized;

	Data* d1 = new Data;
	initData(*d1, "First", 111);
	originalPointers.push_back(d1);

	Data* d2 = new Data;
	initData(*d2, "Second", 222);
	originalPointers.push_back(d2);

	Data* d3 = new Data;
	initData(*d3, "Third", 333);
	originalPointers.push_back(d3);

	std::cout << BLUE << "=== Original objects ===" << RESET << "\n";
	printTableHeader();
	for (size_t i = 0; i < originalPointers.size(); i++)
		printTableRow(*originalPointers[i], i);
	printTableFooter();

	for (size_t i = 0; i < originalPointers.size(); i++) {
		uintptr_t serialized = Serializer::serialize(originalPointers[i]);
		storage.push_back(serialized);
		validSerialized.push_back(serialized);
	}

	std::cout << GREEN << "=== Serialized values stored in database ===" << RESET << "\n";
	for (size_t i = 0; i < storage.size(); i++)
		std::cout  << "Row " << i + 1 << ": " << getRowColor(i) << storage[i] << RESET << "\n";
	std::cout << "\n";

	std::cout << MAGENTA << "=== Restored objects from database ===" << RESET << "\n";
	printTableHeader();
	for (size_t i = 0; i < storage.size(); i++) {
		Data* restored = Serializer::deserialize(storage[i]);
		printTableRow(*restored, i);
	}
	printTableFooter();

	// Corruption
	storage[1] = 123456;

	std::cout << BOLDRED << "=== Restored objects from database with corruption ===" << RESET << "\n";
	printTableHeader();
	for (size_t i = 0; i < storage.size(); i++) {
		if (std::find(validSerialized.begin(), validSerialized.end(), storage[i]) == validSerialized.end()) {
			std::cerr << RED << "Error: Corrupted entry found at row " << i + 1 << RESET << "\n";
			continue;
		}
		Data* restored = Serializer::deserialize(storage[i]);
		printTableRow(*restored, i);
	}
	printTableFooter();

	for (size_t i = 0; i < originalPointers.size(); i++)
		delete originalPointers[i];

	return 0;
}
