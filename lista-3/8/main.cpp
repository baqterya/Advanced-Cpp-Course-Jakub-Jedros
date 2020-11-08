#include <iostream>
#include <string>
#include <vector>

#include "a.h"

int main(){

    A a("hello");
    std::cout << "Wypisuję zawartość a: " << a.get() << "\n";

    A b(a);
    std::cout << "Wypisuję zawartość b: " << b.get() << "\n\n";

    std::vector<A> v;
    std::cout << "Stworzyłem v \n";
    
    v.push_back(A{"one"});

    return 0;
}