#include <iostream>
#include <string>
#include <vector>
#include "wektor.h"


template <typename T, int len>
T operator*(const std::vector<T> &v1, const Wektor<T, len> &v2) {
    T temp = 0;

    try
    {
        if ((int) v1.size() == v2.get_size() && v2.get_size() != 0) {
            for (int i = 0; i < (int) v1.size(); i++)
            {
                temp += v1[i] * v2[i];
            }  
        }
        else
        {
            throw "\nWektory mają inne rozmiary!";
        }
        
        return temp;
    } 
    catch(const char* err) {
        std::cerr << err << std::endl;
        return 0;
    }
}


int main() {

    std::vector<int> v = {1, 2, 3, 4};
    Wektor<int, 3> w;
   
    for (int i = 0; i < 4; i++)
    {
        w.replace(i, i+1);
    }

    std::cout << "wektor std::vector v: " << std::endl;
    for (int i = 0; i < (int) v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
    std::cout << std::endl << "wektor Wektor w = " << std::endl;
    w.print_all();
    std::cout << std::endl << "v * w = " << v * w << std::endl;

    return 0;
}
