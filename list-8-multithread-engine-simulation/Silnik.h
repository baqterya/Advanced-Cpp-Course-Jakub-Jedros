#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

#include "ZbiornikPaliwa.h"

class Silnik {
public:
    // podajemy jaką ilość paliwa spala silnik, czas spalenia ilości, ilość zbiorników i ich rozmiar
    Silnik(const unsigned int &id, const unsigned int &burn, const int &timeout) 
    : _id(id), _timeout(timeout), _burn(burn)
    {
        std::cout << "Tworze silnik " << _id << std::endl;
        _worker = std::thread(&Silnik::looper, this);
    }

    ~Silnik() {
        _worker.join();
        std::cout << "Niszcze silnik nr " << _id << std::endl;
    }

    void dodajZbiornik(const std::shared_ptr<ZbiornikPaliwa> &tank_ptr) {
        std::lock_guard<std::mutex> lock(_mu);
        _zbiorniki.emplace_back(tank_ptr);
    }


private:
    // id silnika
    const unsigned int _id;

    // wektor połączonych zbiorników
    std::vector< std::shared_ptr<ZbiornikPaliwa> > _zbiorniki;

    // czas co jaki zawartość zbiorników będzie aktualizowana
    const int _timeout;

    // ile paliwa ma spalać w odstępie czasowym
    unsigned int _burn;

    // wątek na którym wykona się część programu
    std::thread _worker;

    std::mutex _mu;
    bool end_work = false;

    void looper() {

        std::this_thread::sleep_for(std::chrono::seconds(1));
        while (true)
        {
            {
                std::unique_lock<std::mutex> lock(_mu);

                auto aktualny_zbiornik = _zbiorniki.begin();
                
                if (!_zbiorniki.empty()){
                    end_work = true;
                    std::this_thread::sleep_for(std::chrono::seconds(_timeout));
                }
                else {
                    break;
                }

                std::cout << "\nPraca silnika " << _id << std::endl;
                
                while(!_zbiorniki.empty() && aktualny_zbiornik->get()->pobierz(_burn) == 0) {
                    _zbiorniki.erase(aktualny_zbiornik);
                    aktualny_zbiornik = _zbiorniki.begin();
                }
            }
        }
    }
};