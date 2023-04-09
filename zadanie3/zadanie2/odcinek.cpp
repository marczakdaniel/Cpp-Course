#include "odcinek.hpp"
#include "f_glob.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

Odcinek::Odcinek(Punkt p, Punkt q) {
    if (p.wsp_x() == q.wsp_x() && p.wsp_y() == q.wsp_y()) {
        throw std::invalid_argument("nie można utworzyć odcinka o długości 0");
    }
    else {
        a = p;
        b = q;
    }
}

Odcinek::~Odcinek() {
    a.~Punkt();
    b.~Punkt();
}

Punkt Odcinek::pkt_a() {
    return a;
}

Punkt Odcinek::pkt_b() {
    return b;
}

double Odcinek::dlugosc() {
    return sqrt(pow((a.wsp_x() - b.wsp_x()), 2.0) + pow((a.wsp_y() - b.wsp_y()), 2.0));
}

bool Odcinek::czy_nalezy(Punkt p) {
    if (double_equal(odleglosc(a, p) + odleglosc(b, p), dlugosc())) {
        return true;
    }
    return false;
}

void Odcinek::przesuniecie(Wektor v) {
    a.przesuniecie(v);
    b.przesuniecie(v);
}

void Odcinek::rotacja_punkt(Punkt p, double kat) {
    a.rotacja_punkt(p, kat);
    b.rotacja_punkt(p, kat);
}

void Odcinek::symetria_punkt(Punkt p) {
    a.symetria_punkt(p);
    b.symetria_punkt(p);
}

void Odcinek::symetria_prosta(Prosta l) {
    a.symetria_prosta(l);
    b.symetria_prosta(l);
}

void Odcinek::test() {
    std::cout << "Klasa Odcinek:\n" 
                << "\tPunkt a:\n\t\ta.x = " << a.wsp_x() << "; a.y = " << a.wsp_y() << "\n"
                << "\tPunkt b:\n\t\tb.x = " << b.wsp_x() << "; b.y = " << b.wsp_y() << "\n";
}