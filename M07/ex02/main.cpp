#include "array.hpp"

std::string centerText(const std::string& text, int width) {
    int len = text.size();
    if (len >= width) return text.substr(0, width);
    int left = (width - len) / 2;
    int right = width - len - left;
    return std::string(left, ' ') + text + std::string(right, ' ');
}

template<typename T>
void drawBook(const Array<T>& book, const std::string& title) {
    std::cout << BLUE << "=== " << title << " (" << book.size() << " pages) ===" << RESET << std::endl;

    const int indexWidth = 3;
    const int contentWidth = 12;
    const int addrWidth = 18;

    std::cout << "┌";
    for (int i = 0; i < indexWidth; i++) std::cout << "─";
    std::cout << "┬";
    for (int i = 0; i < contentWidth; i++) std::cout << "─";
    std::cout << "┬";
    for (int i = 0; i < addrWidth; i++) std::cout << "─";
    std::cout << "┐" << std::endl;

    for (unsigned int i = 0; i < book.size(); i++)
	{
		std::string content = book[i];
		if (content.length() > contentWidth - 1)
			content = content.substr(0, contentWidth - 2) + ".";

		std::ostringstream oss;
		oss << &book[i];

		std::cout << "│"
				<< YELLOW << std::setw(indexWidth) << std::right << i << RESET
				<< "│"
				<< GREEN << std::setw(contentWidth) << std::left << content << RESET
				<< "│"
				<< centerText(oss.str(), addrWidth)
				<< "│" << std::endl;
	}
	
    std::cout << "└";
    for (int i = 0; i < indexWidth; i++) std::cout << "─";
    std::cout << "┴";
    for (int i = 0; i < contentWidth; i++) std::cout << "─";
    std::cout << "┴";
    for (int i = 0; i < addrWidth; i++) std::cout << "─";
    std::cout << "┘" << std::endl << std::endl;
}

int main() {
    try {
        std::cout << BLUE << "Creating an empty spellbook..." << RESET << std::endl;
        Array<std::string> emptyBook;
        drawBook(emptyBook, "Empty Book");

        std::cout << BLUE << "Creating a spellbook with 3 spells..." << RESET << std::endl;
        Array<std::string> spellBook(3);
        spellBook[0] = "Fireball";
        spellBook[1] = "Ice Lance";
        spellBook[2] = "Arcane Missiles";
        drawBook(spellBook, "Master's Spellbook");

        std::cout << BLUE << "Copying the spellbook (apprentice makes a copy)..." << RESET << std::endl;
        Array<std::string> apprenticeBook(spellBook);
        apprenticeBook[1] = "Shadow Bolt";
        drawBook(spellBook, "Master's Spellbook");
        drawBook(apprenticeBook, "Apprentice's Spellbook");

        std::cout << BLUE << "Assignment operator test (evil book overwritten)..." << RESET << std::endl;
        Array<std::string> evilBook(10);
        evilBook[0] = "Curse of Weakness";
        evilBook[1] = "Soul Drain";
		
        drawBook(evilBook, "Evil Grimoire BEFORE");

        evilBook = spellBook;
        drawBook(evilBook, "Evil Grimoire AFTER");

        std::cout << BLUE << "Now let's trigger the dark arts (exceptions)..." << RESET << std::endl;
        std::cout << spellBook[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}

