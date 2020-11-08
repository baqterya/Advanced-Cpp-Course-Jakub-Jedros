#include <iostream>
#include <type_traits>

#include "a.h"

template <typename T>
const A copy(T&& myA) {
    if (std::is_rvalue_reference<decltype(myA)>::value) {
        std::cout << "jestem r-value\n";

        return std::move(myA);
    }
    else {
        std::cout << "nie jestem r-value\n";

        return myA;
    }
    
}

int main() {

    A obiekt1("oryginał");
    A obiekt2 = copy(obiekt1);
    A obiekt3 = copy(A("to powinno byc r-value"));

    std::cout << "Zawartosc obiekt1: " << obiekt1.get() << std::endl;
    std::cout << "Zawartosc obiekt2: " << obiekt2.get() << std::endl;
    std::cout << "Zawartosc obiekt3: " << obiekt3.get() << std::endl;
}