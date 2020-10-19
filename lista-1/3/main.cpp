#include <iostream>
#include <string>

#include "wektor.h"


int main() {
    std::cout << "TEST WEKTORA" << std::endl;
    
    std::cout << std::endl << "Inicjalizacja zerami" << std::endl;
    Wektor<int, 5> w;
    w.print_all();

    std::cout << std::endl << "Dodanie Elementu na koniec wiersza" << std::endl;
    w.push_back(2);
    w.print_all();

    std::cout << std::endl << "Podmiana drugiego Elementu na inną liczbę" << std::endl;
    w.replace(2, 8);
    w.print_all();

    std::cout << std::endl << "Usunięcie elementu z wektora" << std::endl;
    w.remove_slot(2);
    w.print_all();

    std::cout << std::endl << "Zresetowanie wartości elementów wektora" << std::endl;
    w.clear();
    w.print_all();


    return 0;
}