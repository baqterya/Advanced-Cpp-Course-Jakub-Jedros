#include <iostream>
#include <string>


template <typename T, typename Y>
auto add1(const T& object1, const Y& object2) {
    return object1 + object2;
}

template<typename T, typename Y>
auto add1(const T* const object1, const Y* const object2) {
    return *object1 + *object2;
}

template<>
auto add1(const char *object1, const char *object2) {
    return std::string(object1) + object2;
}

int main() {
    /*
    std::cout << "int + int = " << add1(1, 2) << std::endl;
    
    std::cout << "float + float = " << add1(2.0, 3.3) << std::endl;

    std::cout << "int + float = " << add1(1, 3.33) << std::endl;
    
    std::string str_a = "Hello";
    std::string str_b = " world";
    std::cout << "string + string = " << add1(str_a, str_b) << std::endl;
    */
  
    double double_a = 3.1;
    double double_b = 4.4;

    const char* char_a = "A";
    const char* char_b = "B";

    std::cout << "Oryginalne add1\n" << double_a << " + " << double_b << " = " << add1(double_a, double_b) << std::endl;
    
// PB: Właśnie ten błąd trzeba było w tym zadaniu naprawić, tak żeby działało bez podawania typów szablonu.
// PB: Zadanie nie jest rozwiązanie.
    //dziwny blad jesli nie sprecyzuje typow zmiennych w <> przed overloadem add1 
    //std::enable_if
    std::cout << "\nOverload dla *\n" << double_a << " + " << double_b << " = "  << add1<const double, const double>(&double_a, &double_b) << std::endl;
    std::cout << "\nSpecjalizacja dla const char*\n" << "A + B = " << add1(char_a, char_b) << std::endl;


    return 0;
}
