#include <iostream>

#include "myClass.h"


double funToPass() {
    double a = 67108864;
    while (a > 2)
        a /= 2;
    return a;
}

int main() {
    
    myClass test(8);
    
    test.add_task(funToPass);
    test.stop();

    std::cout << "average = " << test.average() << std::endl;

    return 0;
}