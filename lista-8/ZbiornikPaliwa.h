#pragma once

#include <iostream>

class ZbiornikPaliwa{
public:
    ZbiornikPaliwa(const unsigned int &id, const unsigned int &poj) : _id(id), _zawartosc(poj)
    {}

    ~ZbiornikPaliwa() {
        std::cout << "Zbiornik " << _id << " zniszczony" << std::endl;
    }

    unsigned int pobierz(unsigned int &n) {
        std::lock_guard<std::mutex> lock(_tank_mu);
        
        if ( n > _zawartosc ) {
            return 0;
        }
        else{
            _zawartosc -= n;
        
            std::cout << "Pobrano " << n << " paliwa ze zbiornika " << _id;
            std::cout << ";     Pozostało " << _zawartosc << std::endl;
        
            return _zawartosc;
        }
    }

private:
    const unsigned int _id;
    unsigned int _zawartosc;
    std::mutex _tank_mu;
};