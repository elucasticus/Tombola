#include "tabellone.hpp"
#include <sstream>
#include <string>

using namespace Tombola;

int main(int argc, char** argv)
{
    unsigned int n = 90;
    Tabellone tab(n);
    unsigned int i = 0;
    while (i < 90) {
        std::string input;
        std::cout << "Cosa vuoi fare? [e, c, exit]" << std::endl;
        std::cin >> input;
        if (input == "e") {
            tab.estrai_numero();
            tab.stampa_tabellone();
            ++i;
        } else if (input == "c") {
            try {
                std::cout << "Sequenza: " << std::endl;
                std::string my_string;
                std::cin.ignore();
                std::getline(std::cin, my_string);
                std::stringstream iss(my_string);
                unsigned int number;
                std::vector<unsigned int> my_numbers;
                while (iss >> number) {
                    my_numbers.push_back(number);
                }
                std::cout << tab.controlla_sequenza(my_numbers) << std::endl;
                ++i;
            } catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        } else if (input == "exit") {
            i = n;
        }
    }
    return 0;
}
