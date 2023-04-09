#include <iostream>
#include <cmath>

#include "f_glob.hpp"
#include "punkt.hpp"
#include "odcinek.hpp"
#include "trojkat.hpp"
#include "prosta.hpp"
#include "wektor.hpp"

int main() {
    // Testy klasy Punkt
    std::cout << "----Test klasy Punkt----\n";
    Punkt punkt1(4.35, 3.543);
    Punkt punkt2;
    Punkt punkt3 = Punkt(-1232, 34.3);
    punkt1.test();
    punkt2.test();
    punkt3.test();
    punkt1.~Punkt();
    punkt1.test();
    std::cout << "----Test: odleglosc()----\n";
    std::cout << odleglosc(Punkt(0.0, 0.0), Punkt(3.0, 4.0)) << "\n";
    std::cout << odleglosc(Punkt(3.23234, -4.3434), Punkt(-10.43443, 7.34344)) << "\n";
    std::cout << odleglosc(Punkt(7.0, 7.0), Punkt(7.0, 7.0)) << "\n";
    std::cout << "----Test: przesuniecie()----\n";
    punkt3.test();
    punkt3.przesuniecie(Wektor(1000, -0.3));
    punkt3.test();
    std::cout << "----Test: rotacja_punkt()----\n";
    Punkt punkt(100.0, 100.0);
    punkt.test();
    punkt.rotacja_punkt(Punkt(0, 0), 90);
    punkt.test();
    punkt = Punkt(100.0, 100.0);
    punkt.test();
    punkt.rotacja_punkt(Punkt(1, 1), 180);
    punkt.test();
    punkt.test();
    punkt.rotacja_punkt(Punkt(12.34, -13434.2), 3674.4);
    punkt.test();
    std::cout << "----Test: symetria_punkt()----\n";
    punkt = Punkt(100.0, 100.0);
    punkt.test();
    punkt.symetria_punkt(Punkt(1, 1));
    punkt.test();
    std::cout << "----Test: symetria_prosta()----\n";
    Punkt punktS(4.0, 7.0);
    punktS.test();
    punktS.symetria_prosta(Prosta(0.0, 0.0, 0.0, 3.0));
    punktS.test();
    Punkt punktS2(4.0, 7.0);
    punktS2.test();
    punktS2.symetria_prosta(Prosta(0.0, 0.0, 3.0, 3.0));
    punktS2.test();

    // Testy klasy Odcinek
    std::cout << "----Test klasy Odcinek----\n";
    Odcinek odcinek1(Punkt(3, 4), Punkt(4, 5));
    odcinek1.test();
    // Odcinek odcinek2(Punkt(3, 4), Punkt(3, 4));
    Odcinek odcinek3(Punkt(34.3434, -2323.34), Punkt(-23234, -343.34343));
    odcinek3.test();
    std::cout << odcinek1.dlugosc() << "\n";
    std::cout << odcinek3.dlugosc() << "\n";
    odcinek3.~Odcinek();
    odcinek3.test();
    std::cout << "----Test: czy_nalezy()----\n";
    std::cout << Odcinek(Punkt(0.0, 0.0), Punkt(10.0, 10.0)).czy_nalezy(Punkt(5.0, 5.0)) << "\n";
    std::cout << Odcinek(Punkt(0.0, 0.0), Punkt(10.0, 10.0)).czy_nalezy(Punkt(10.0, 10.0)) << "\n";
    std::cout << Odcinek(Punkt(0.0, 0.0), Punkt(10.0, 10.0)).czy_nalezy(Punkt(7.0, 1002.0)) << "\n";
    std::cout << Odcinek(Punkt(0.0, 0.0), Punkt(10.0, 10.0)).czy_nalezy(Punkt(7.0, -1002.0)) << "\n";
    std::cout << Odcinek(Punkt(0.0, 0.0), Punkt(10.0, 10.0)).czy_nalezy(Punkt(11.0, 11.0)) << "\n";
    odcinek1 = Odcinek(Punkt(1.0, 1.0), Punkt(10.0, 10.0));
    std::cout << "----Test: czy_rownolegle()----\n";
    std::cout << czy_rownolegle(odcinek1, Odcinek(Punkt(3.0, 3.0), Punkt(13.0, 13.0))) << "\n";
    std::cout << czy_rownolegle(odcinek1, Odcinek(Punkt(3.0, 3.0), Punkt(13.0, 14.0))) << "\n";
    std::cout << czy_rownolegle(odcinek1, Odcinek(Punkt(90.0, 100.0), Punkt(100.0, 90.0))) << "\n";
    std::cout << "----Test: czy_prostopadle()----\n";
    std::cout << czy_prostopadle(odcinek1, Odcinek(Punkt(3.0, 3.0), Punkt(13.0, 13.0))) << "\n";
    std::cout << czy_prostopadle(odcinek1, Odcinek(Punkt(3.0, 3.0), Punkt(13.0, 14.0))) << "\n";
    std::cout << czy_prostopadle(odcinek1, Odcinek(Punkt(90.0, 100.0), Punkt(100.0, 90.0))) << "\n";
    std::cout << "----Test: przesuniecie()----\n";
    odcinek1.test();
    odcinek1.przesuniecie(Wektor(1.5, -2.0));
    odcinek1.test();
    std::cout << "----Test: rotacja_punkt()----\n";
    odcinek1.test();
    odcinek1.rotacja_punkt(Punkt(12.34, -13434.2), 3674.4);
    odcinek1.test();
    std::cout << "----Test: symetria_punkt()----\n";
    odcinek1 = Odcinek(Punkt(1.0, 1.0), Punkt(10.0, 10.0));
    odcinek1.test();
    odcinek1.symetria_punkt(Punkt(1, 1));
    odcinek1.test();
    std::cout << "----Test: symetria_prosta()----\n";
    odcinek1.test();
    odcinek1.symetria_prosta(Prosta(0.0, 0.0, 0.0, 3.0));
    odcinek1.test();

    // Test klasy Trojkat
    std::cout << "----Test klasy Trojkat----\n";
    Trojkat trojkat1(Punkt(1.234, 3.343), Punkt(3.232, 4.3), Punkt(-3.236, 7.2343));
    trojkat1.test();
    // Trojkat trojkat_zly(Punkt(1, 1), Punkt(2, 2), Punkt(3, 3));
    Trojkat trojkat2(Punkt(0, 0), Punkt(0, 3), Punkt(4, 0));
    trojkat2.test();
    Trojkat trojkat3(Punkt(0.343, 0), Punkt(0, 3.232), Punkt(4, 0));
    trojkat3.test();
    trojkat3.~Trojkat();
    trojkat3.test();
    std::cout << "----Test: obwod()----\n";
    std::cout << trojkat1.obwod() << "\n";
    std::cout << trojkat2.obwod() << "\n";
    std::cout << "----Test: pole()----\n";
    std::cout << trojkat1.pole() << "\n";
    std::cout << trojkat2.pole() << "\n";
    std::cout << "----Test: czy_nalezy()----\n";
    std::cout << trojkat2.czy_nalezy(Punkt(0, 0)) << "\n";
    std::cout << trojkat2.czy_nalezy(Punkt(0.98 , 1.01)) << "\n";
    std::cout << trojkat2.czy_nalezy(Punkt(-10.343, -4.343)) << "\n";
    std::cout << "----Test: czy_zawiera()----\n";
    Trojkat trojkatA(Punkt(0, 0), Punkt(0, 6), Punkt(7, 0));
    Trojkat trojkatB(Punkt(0, 0), Punkt(0, 6), Punkt(6, 0));
    Trojkat trojkatC(Punkt(0, 0), Punkt(0, 6), Punkt(5, 11));
    std::cout << czy_zawiera(trojkatA, trojkatB) << "\n";
    std::cout << czy_zawiera(trojkatB, trojkatA) << "\n";
    std::cout << czy_zawiera(trojkatA, trojkatC) << "\n";
    std::cout << "----Test: czy_rozlaczne()----\n";
    std::cout << czy_rozlaczne(trojkatA, trojkatB) << "\n";
    std::cout << czy_rozlaczne(trojkatB, trojkatA) << "\n";
    std::cout << czy_rozlaczne(trojkatA, trojkatC) << "\n";
    std::cout << "----Test: przesuniecie()----\n";
    trojkatA.test();
    trojkatA.przesuniecie(Wektor(1, -7));
    trojkatA.test();
    std::cout << "----Test: rotacja_punkt()----\n";
    trojkatA.test();
    trojkatA.rotacja_punkt(Punkt(12.34, -13434.2), 3674.4);
    trojkatA.test();
    std::cout << "----Test: symetria_punkt()----\n";
    trojkatB.test();
    trojkatB.symetria_punkt(Punkt(1, 1));
    trojkatB.test();
    std::cout << "----Test: symetria_prosta()----\n";
    trojkatC.test();
    trojkatC.symetria_prosta(Prosta(0.0, 0.0, 0.0, 3.0));
    trojkatC.test();
}