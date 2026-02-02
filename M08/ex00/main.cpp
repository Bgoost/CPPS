#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <ctime>


template <typename T>
void show_container(const T &container) {
    std::cout << "[ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]";
}

int main() {
    std::srand(std::time(0));

    std::cout << BLUE << "====================================================================" << RESET << std::endl;
    std::cout << BLUE << "  🎮 WELCOME TO NUMBER HUNTER 🎮\t\t[HIDE THIS COLUMN]" << RESET << std::endl;
    std::cout << BLUE << "====================================================================" << RESET << std::endl;
    std::cout << "3 hidden numbers (1-10) are stored in boxes." << std::endl;
    std::cout << "Guess a number. If it's in the box, you win a point." << std::endl;
    std::cout << "You have 5 lives. Get 3 points to win the game!" << std::endl;

    std::vector<int> box;
    std::vector<bool> guessed(3, false);
	int i = 0;
	while(box.size() < 3)
	{
		int num = std::rand() % 10 + 1;
		if(std::find(box.begin(), box.end(), num) == box.end())
		{
			box.push_back(num);
			++i;
		}
	}
	std::cin.get();

    int score = 0;
    int attempts = 0;

    while (score < 3 && attempts < 5) {
        std::cout << BLUE << "====================================================================" << RESET << std::endl;
        std::cout << "Score: " << score << " / 3\t\t";
        for(int i = 0; i < 5 - attempts; ++i) std::cout << "❤️ ";

        std::cout << "\nBox contents:\t\t\t\t\t    ";
        show_container(box);
        std::cout << std::endl;

        std::cout << "Enter a number to search: ";
        int guess;
        if (!(std::cin >> guess)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected (Ctrl+D). Exiting game..." << std::endl;
            } else {
                std::cout << "\nInvalid input detected. Exiting game..." << std::endl;
            }
            return 0;
        }

        if (guess == 0)
			return (std::cout << "Zero detected, exiting now..." << std::endl, 0);
        try {
            int a = easyfind(box, guess);
            if(!guessed[a])
                score++;
            guessed[a] = true;
            
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            attempts++;
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << BLUE << "====================================================================" << RESET << std::endl;
    if (score >= 3)
        std::cout << YELLOW << "\t🏆 VICTORY! You're the Number Hunter Champion! 🏆" << RESET << std::endl;
    else
        std::cout << RED << "\t💀 GAME OVER! The numbers have failed you... 💀" << RESET << std::endl;

    std::cout << BLUE << "====================================================================" << RESET << std::endl;
    return 0;
}
