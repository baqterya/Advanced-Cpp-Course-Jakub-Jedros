#include <iostream>
#include <string>

class Character
{
public:
    //Dla porównania tworzę metodę zwykłą i wirtualną zwracające stringa
    std::string GetName()   {return "Base Character Class";}
    virtual std::string VirtualGetName()   {return "Base Character Class";}
};

class Player : public Character
{
private:
    std::string P_Name;
public:
    Player(const std::string& Name) : P_Name(Name) {}

    //klasa Player próbuje nadpisać obie funkcje klasy Character
    std::string GetName() {return P_Name;}
    std::string VirtualGetName() override {return P_Name;}
};


void Print(Character* character)
{
    std::cout << "Metoda normalna:      " << character->GetName() << std::endl;
    std::cout << "Metoda wiurtualna:    " << character->VirtualGetName() << std::endl;
    std::cout << std::endl;
}

int main() {

    Character* c = new Character();
    std::cout << "wyniki obu metod metod dla obiektu klasy Character" << std::endl;
    Print(c);

    Player* p = new Player("Player");
    std::cout << "wyniki obu metod metod dla obiektu klasy Player" << std::endl;
    Print(p);

    return 0;
}
