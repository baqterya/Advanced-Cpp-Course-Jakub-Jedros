#include <iostream>
#include <string>


template <typename A, typename B, typename C>
auto add2(A funA, B argB, C argC){ //stala referncja
    return funA(argB, argC);
}


int main(){

    std::cout << "Do każdego punktu używam funkcji zdefiniowanej lambdą"
    << std::endl << std::endl;
    
    auto lambda1 = [](auto a, auto b) {return a + b;};


    std::cout << "2 + 3 = " << add2(lambda1, 2, 3) << std::endl;
    std::cout << "2 + 3.33 = "  << add2(lambda1, 2, 3.33) << std::endl;

    std::string s1 = "foo";
    std::string s2 = "bar";
    std::cout << "'foo' + 'bar' = " << add2(lambda1, s1, s2) << std::endl;

    return 0;
}