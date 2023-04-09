#ifndef PUNKT_HPP
#define PUNKT_HPP

#include "wektor.hpp"
#include "prosta.hpp"

class Punkt {
    private:
        double x;
        double y;
    public:
        Punkt();
        Punkt(double a, double b);
        ~Punkt();

        double wsp_x();
        double wsp_y();

        void przesuniecie(Wektor v);
        void rotacja_punkt(Punkt p, double kat);
        void symetria_punkt(Punkt p);
        void symetria_prosta(Prosta l);

        void test();

};

#endif // PUNKT_HPP