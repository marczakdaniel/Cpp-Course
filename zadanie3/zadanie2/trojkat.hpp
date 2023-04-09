#ifndef TROJKAT_HPP
#define TROJKAT_HPP

#include "punkt.hpp"
#include "wektor.hpp"

class Trojkat {
    private:
        Punkt a;
        Punkt b;
        Punkt c;
    public:
        Trojkat(Punkt x, Punkt y, Punkt z);
        ~Trojkat();

        double obwod();
        double pole();
        bool czy_nalezy(Punkt p);

        Punkt pkt_a();
        Punkt pkt_b();
        Punkt pkt_c();

        void przesuniecie(Wektor v);
        void rotacja_punkt(Punkt p, double kat);
        void symetria_punkt(Punkt p);
        void symetria_prosta(Prosta l);

        void test();
};

#endif // TROJKAT_HPP