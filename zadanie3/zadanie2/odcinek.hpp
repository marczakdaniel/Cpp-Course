#ifndef ODCINEK_HPP
#define ODCINEK_HPP

#include "punkt.hpp"
#include "wektor.hpp"

class Odcinek {
    private:
        Punkt a;
        Punkt b;
    public:
        Odcinek(Punkt p, Punkt q);
        ~Odcinek();

        Punkt pkt_a();
        Punkt pkt_b();

        double dlugosc();
        bool czy_nalezy(Punkt p);

        void przesuniecie(Wektor v);
        void rotacja_punkt(Punkt p, double kat);
        void symetria_punkt(Punkt p);
        void symetria_prosta(Prosta l);

        void test();
};

#endif // ODCINEK_HPP