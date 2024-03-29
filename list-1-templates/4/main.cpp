#include <iostream>
#include <string>
#include <vector>
#include "wektor.h"


template <typename T, int len>
T operator*(const std::vector<T> &v1, const Wektor<T, len> &v2) {
    T temp = 0;

    try
    {
        //static cast zamiast (typ)
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

template <typename T, int len>
T operator*(const Wektor<T, len> &v2, const std::vector<T> &v1) {
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

    std::vector<int> v = {1, 2, 3};
    std::vector<int> v2 = {1, 2, 3, 4};
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
    
    std::cout << "\n\nwektor Wektor w = " << std::endl;
    w.print_all();
    std::cout << "\nv * w = " << v * w << std::endl;
    std::cout << "w * v = " << v * w << std::endl;

    std::cout << "Kiedy wektory są nierówne: " << std::endl;
    std::cout << "v2 * w = " << v2 * w << std::endl;

    return 0;
}
