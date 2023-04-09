#include "liczba.hpp"

int main() {
    Liczba l = Liczba(1);
    l.test();
    l.przypisz(2);
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    l.przypisz(2);
    l.test();
    l.przypisz(3);
    l.test();
    l.przypisz(4);
    l.test();
    l.przypisz(5);
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    l.przywroc_historie();
    l.test();
    std::cout << "\n";
    Liczba l2 = Liczba();
    l2.test();
    std::cout << "\n";
    Liczba l3 = Liczba(l);
    l3.test();
    std::cout << "\n";
    Liczba l4 = l3;
    l3.test();
    l4.test();
    Liczba l5;
    l5 = std::move(l5);
    l5.test();
}