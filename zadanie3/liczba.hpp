#ifndef LICZBA_HPP
#define LICZBA_HPP

#include <iostream>

class Liczba {
    const static int rozmiar = 3;
    private:
        double liczba;
        double *historia;
        int elem_hist;
        int przywrocen;
    public:
        Liczba(double l);
        Liczba();
        Liczba(const Liczba &l);
        Liczba(Liczba &&l);
        Liczba& operator=(Liczba &&l);
        Liczba& operator=(const Liczba &l);
        ~Liczba();
        void przypisz(double l);
        void przywroc_historie();
        void test();
};

#endif // LICZBA_HPP