#include <iostream>
#include <string>


template <typename T, typename Y>
auto add1(T object1, Y object2) {

    return object1 + object2;
}
template<>
auto add1(double *a, double *b) {
    std::cout << "uzywam specjalizacji\n";
    return *a + *b;
}

char add1(const char *a, const char *b) {
    std::cout << "uzywam wersji charowej\n";
    return *a + *b;
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

    const char char_a = 'A';
    const char char_b = 'B';

    std::cout << "Oryginalne add1\n" << add1(double_a, double_b) << std::endl;
    std::cout << "\nWyspecjalizowane add1\n" << add1(&double_a, &double_b) << std::endl;
    std::cout << "\nWersja add1 dla char\n" << add1(&char_a, &char_b) << std::endl;


    return 0;
}