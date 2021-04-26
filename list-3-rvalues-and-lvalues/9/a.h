#pragma once

#include <iostream>
#include <string>
#include <cstring>

class A {

    public:

        A(const std::string& myString)
        : length{myString.length()}, text{new char[length + 1]} {
            std::cout << "\nKonstruktor przyjmujący referencję\n";

            myString.copy(text, length);
            text[length] = '\0';
            std::cout << "Konstruuję '" << text << "'\n";
        }

        A(const A& myA)
        : length{myA.length}, text{new char[length + 1]} {
            std::cout << "\nKonstruktor kopiujący\n";

            std::memcpy(text, myA.text, length + 1);
            std::cout << "Kopiuję '" << text  << "'\n";
        }

        A(A&& myA)
        : length{myA.length}, text{myA.text} {
            std::cout << "\nKonstruktor przenoszący\n";

            myA.text = nullptr;
            std::cout << "Przenoszę '" << text  << "'\n";
        }

        const char* get() const {
            return text;
        }

        ~A() {
            std::cout << "\nDestruktor\n";
            
            delete[] text;
        }


    private:

        size_t length;
        char* text;
};