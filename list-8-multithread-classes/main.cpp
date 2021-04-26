#include <iostream>
#include <memory>

#include "Silnik.h"

class Entity
{
private:
    int _n;

public:
    Entity(int n) {
        std::cout << "I'm created" << std::endl;
        _n = n;
    }

    ~Entity(){
        std::cout << "I'm destroyed" << std::endl;
    }

    void print() {
        std::cout << _n << std::endl;
    }
};

int main() {
    std::vector< std::shared_ptr<ZbiornikPaliwa> > zbiorniki;
    for (int i = 0; i < 10; i++) {
        zbiorniki.emplace_back(std::make_shared<ZbiornikPaliwa>(i, 10 + i));
    }

    Silnik silnik0(0, 5, 2);
    Silnik silnik1(1, 1, 1);
    Silnik silnik2(2, 2, 3);
        
    for (auto &zbiornik : zbiorniki)
    {
        silnik0.dodajZbiornik(zbiornik);
        silnik1.dodajZbiornik(zbiornik);
        silnik2.dodajZbiornik(zbiornik);
    }   

    return 0;
}