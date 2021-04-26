#include <iostream>
#include <string>


template <typename T, typename Y>
void add1(T object1, Y object2) //przekazac przez stala referencje
{
    std::cout << object1 + object2 << std::endl << std::endl;
}


int main() {

    std::cout << "int + int" << std::endl;
    add1(1, 2);

    std::cout << "float + float" << std::endl;
    add1(2.0, 3.3);

    std::cout << "int+ float" << std::endl;
    add1(1, 3.33);

    std::string a = "Hello";
    std::string b = " world";
    std::cout << "string + string" << std::endl;
    add1(a, b);

    return 0;
}