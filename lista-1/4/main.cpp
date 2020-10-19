#include <iostream>
#include <string>
#include <vector>
#include "wektor.h"

template <typename T, int len>
T operator*(const std::vector<T> &v1, const Wektor<T, len> &v2) {
    T temp = 0;
    for (int i = 0; i < (int) v1.size(); i++)
    {
        temp += v1[i] * v2[i];
    }
        
    return temp;      
}


int main() {

    std::vector<int> v = {1, 2, 3};
    Wektor<int, 3> w;
   
    for (int i = 0; i < 4; i++)
    {
        w.replace(i, i+1);
    }

    std::cout << v * w << std::endl;

    return 0;
}
