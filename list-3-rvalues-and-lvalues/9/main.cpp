#include <iostream>
#include <type_traits>

#include "a.h"

const A copy(const A& myA) {
    
    //return A(myA); ???
    return A(myA);
}

const A copy(A&& myA) {

    //return std::move(A(myA));
    return A(std::move(myA));
}

int main(){

    A obiekt1("oryginal");
    A obiekt2 = copy(obiekt1);

    A obiekt3 = copy(A("tu powinien byc prznoszacy"));

    std::cout << "Zawartosc obiekt1: " << obiekt1.get() << std::endl;
    std::cout << "Zawartosc obiekt2: " << obiekt2.get() << std::endl;
    std::cout << "Zawartosc obiekt3: " << obiekt3.get() << std::endl;

    return 0;
}