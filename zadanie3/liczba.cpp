#include "liczba.hpp"

Liczba::Liczba(double l) {
    liczba = l;
    historia = new double[rozmiar];
    historia[0] = l;
    elem_hist = 1;
    przywrocen = 1;
}

Liczba::Liczba() : Liczba(0) {

}

Liczba::Liczba(const Liczba &l) {
    liczba = l.liczba;
    historia = new double[rozmiar];
    elem_hist = 1;
    przywrocen = 1;
    historia[0] = l.liczba;
}

Liczba& Liczba::operator=(const Liczba &l) {
    if (this != &l) {
        liczba = l.liczba;
        historia = new double[rozmiar];
        elem_hist = 1;
        przywrocen = 1;
        historia[0] = l.liczba;
    }
    
    return *this;
}

Liczba::Liczba(Liczba &&l) {
    liczba = l.liczba;
    historia = l.historia;
    elem_hist = l.elem_hist;
    przywrocen = l.przywrocen;

    l.liczba = 0;
    l.historia = nullptr;
    l.elem_hist = 0;
    l.przywrocen = 0;
}

Liczba& Liczba::operator=(Liczba &&l) {
    if (this != &l) {
        liczba = l.liczba;
        historia = l.historia;
        elem_hist = l.elem_hist;
        przywrocen = l.przywrocen;

        l.liczba = 0;
        l.historia = nullptr;
        l.elem_hist = 0;
        l.przywrocen = 0;
    }
    return *this;
}

Liczba::~Liczba() {
    delete[] historia;
}

void Liczba::przypisz(double l) {
    historia[elem_hist % rozmiar] = liczba;
    elem_hist++;
    liczba = l;
    if (przywrocen < rozmiar - 1) przywrocen++;
}

void Liczba::przywroc_historie() {
    liczba = historia[(elem_hist - 1) % rozmiar];
    if (elem_hist > 1 && przywrocen != 0) {
        elem_hist--;
        przywrocen--;
    }
}

void Liczba::test() {
    std::cout << "liczba: " << liczba << " rozmiar: "<< elem_hist << " przywrocen: " << przywrocen << "\n";
}