#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=== MutantStack Test ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating MutantStack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "--- Compare with std::list ---" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Back: " << lst.back() << std::endl;
    lst.pop_back();

    std::cout << "Size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating std::list:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
// #include "MutantStack.hpp"
// #include <iostream>
// #include <string>

// template <typename T>
// void show_stack(const MutantStack<T> &stack) {
//     if (stack.empty()) {
//         std::cout << "\n🍽️ The tower is empty. No food to show." << std::endl;
//         return;
//     }

//     std::cout << std::endl << std::endl;
//     std::cout << "      🏗️ FOOD TOWER 🏗️" << std::endl;
//     std::cout << "-------------------------" << std::endl;
   
//     std::cout << "          (TOP)" << std::endl;

//     typename MutantStack<T>::const_reverse_iterator it = stack.rbegin();
//     for (; it != stack.rend(); ++it) {
//         std::ostringstream oss;
//         oss << *it;
//         std::string food = oss.str();

//         if (food.length() > 15) food = food.substr(0, 14) + ".";
//         int padding = (15 - food.length()) / 2;

//         std::cout << "    +=======╩=======+" << std::endl;
//         std::cout << "    |" << std::string(padding, ' ')
//                   << food
//                   << std::string(15 - padding - food.length(), ' ')
//                   << "|" << std::endl;
//         std::cout << "    +=======╦=======+" << std::endl;
//     }

//     std::cout << "         (BOTTOM)" << std::endl;
//     std::cout << "-------------------------";
// }


// int main() {
//     std::cout << MAGENTA << "Ey ey ey pequeña, te tengo que avisar que este programa tiene un pequeño problema... \nSi haces Ctrl+C hay leaks, ya que cierras el programa de forma abrupta. Si fuese \nun programa pedido por el subject, lo habría gestionado mejor con señales y todo, \npero no creo que sea necesario para esta demostración." << RESET << std::endl;
//     std::cout << BLUE << "==========================================================" << RESET << std::endl;
//     std::cout << CYAN << "      🍔 WELCOME TO THE MUTANTSTACK CAFÉ 🍔" << RESET << std::endl;
//     std::cout << BLUE << "==========================================================" << RESET << std::endl;

//     MutantStack<std::string> tray;

//     bool running = true;
//     while (running) {
//         std::cout << "\n" << YELLOW << "What would you like to do?" << RESET << std::endl;
//         std::cout << "1. Add order (push)" << std::endl;
//         std::cout << "2. Serve order (pop)" << std::endl;
//         std::cout << "3. Peek at current order (top)" << std::endl;
//         std::cout << "4. Show all orders (iterate)" << std::endl;
//         std::cout << "5. Quit Café" << std::endl;

//         std::string choice;
//         std::cout << GREEN << "👉 Enter choice: " << RESET;
//         if (!(std::cin >> choice)) {
//             std::cout << RED << "Invalid input. Exiting..." << RESET << std::endl;
//             break;
//         }
//         if((choice.length() != 1 || choice[0] < '1' || choice[0] > '5') && choice != "push" && choice != "pop" && choice != "top" && choice != "iterate" && choice != "quit") {
//             std::cout << RED << "Invalid option. Try again." << RESET << std::endl;
//             continue;
//         }
//         if(choice == "push") choice = "1";
//         else if(choice == "pop") choice = "2";
//         else if(choice == "top") choice = "3";
//         else if(choice == "iterate") choice = "4";
//         else if(choice == "quit") choice = "5";
//         int opt = choice[0] - '0';
//         switch (opt) {
//             case 1: {
//                 std::cout << "Enter new order (e.g. Cafe, Soda, Cookies): ";
//                 std::string order;
//                 std::cin >> order;
//                 tray.push(order);
//                 std::cout << GREEN << "✅ Added " << order << " to the tray." << RESET << std::endl;
//                 break;
//             }
//             case 2: {
//                 if (tray.empty()) {
//                     std::cout << RED << "❌ Tray is empty. Nothing to serve." << RESET << std::endl;
//                 } else {
//                     std::cout << "🍽️ Served: " << tray.top() << std::endl;
//                     tray.pop();
//                 }
//                 break;
//             }
//             case 3: {
//                 if (tray.empty()) {
//                     std::cout << RED << "❌ Tray is empty." << RESET << std::endl;
//                 } else {
//                     std::cout << "👀 Current order on top: " << YELLOW << tray.top() << RESET << std::endl;
//                 }
//                 break;
//             }
//             case 4: {
//                 if (tray.empty()) {
//                     std::cout << RED << "❌ Tray is empty." << RESET << std::endl;
//                 } else {
//                     std::cout << "📝 Orders in tray: ";
//                     show_stack(tray);
//                     std::cout << std::endl;
//                 }
//                 break;
//             }
//             case 5:
//                 std::cout << CYAN << "👋 Thanks for visiting the MutantStack Café! Come again!" << RESET << std::endl;
//                 running = false;
//                 break;
//             default:
//                 std::cout << RED << "Invalid option. Try again." << RESET << std::endl;
//         }
//     }

//     return 0;
// }
