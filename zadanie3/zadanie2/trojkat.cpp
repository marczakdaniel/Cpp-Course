#include "trojkat.hpp"
#include "f_glob.hpp"
#include <stdexcept>
#include <iostream>

Trojkat::Trojkat(Punkt x, Punkt y, Punkt z) {
    double x1 = x.wsp_x();
    double y1 = x.wsp_y();
    double x2 = y.wsp_x();
    double y2 = y.wsp_y();
    double x3 = z.wsp_x();
    double y3 = z.wsp_y();
    double test = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (double_equal(test, 0.0)) {
        throw std::invalid_argument("nie można utworzyć trojkąta z punktów współliniowych");
    }
    else {
        a = x;
        b = y;
        c = z;
    }
} 

Trojkat::~Trojkat() {
    a.~Punkt();
    b.~Punkt();
    c.~Punkt();
}

double Trojkat::obwod() {
    return odleglosc(a, b) + odleglosc(b, c) + odleglosc(a, c);
}

double Trojkat::pole() {
    double x1 = a.wsp_x();
    double y1 = a.wsp_y();
    double x2 = b.wsp_x();
    double y2 = b.wsp_y();
    double x3 = c.wsp_x();
    double y3 = c.wsp_y();
    double wynik = 0.5 * std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    return wynik;
}

double sign(Punkt p1, Punkt p2, Punkt p3) {
    double x1 = p1.wsp_x();
    double y1 = p1.wsp_y();
    double x2 = p2.wsp_x();
    double y2 = p2.wsp_y();
    double x3 = p3.wsp_x();
    double y3 = p3.wsp_y();
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

bool Trojkat::czy_nalezy(Punkt p) {
    double d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(p, a, b);
    d2 = sign(p, b, c);
    d3 = sign(p, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

Punkt Trojkat::pkt_a() {
    return a;
}

Punkt Trojkat::pkt_b() {
    return b;
}

Punkt Trojkat::pkt_c() {
    return c;
}

void Trojkat::przesuniecie(Wektor v) {
    a.przesuniecie(v);
    b.przesuniecie(v);
    c.przesuniecie(v);
}

void Trojkat::rotacja_punkt(Punkt p, double kat) {
    a.rotacja_punkt(p, kat);
    b.rotacja_punkt(p, kat);
    c.rotacja_punkt(p, kat);
}

void Trojkat::symetria_punkt(Punkt p) {
    a.symetria_punkt(p);
    b.symetria_punkt(p);
    c.symetria_punkt(p);
}

void Trojkat::symetria_prosta(Prosta l) {
    a.symetria_prosta(l);
    b.symetria_prosta(l);
    c.symetria_prosta(l);
}

void Trojkat::test() {
    std::cout << "Klasa Trojkat:\n" 
                << "\tPunkt a:\n\t\ta.x = " << a.wsp_x() << "; a.y = " << a.wsp_y() << "\n"
                << "\tPunkt b:\n\t\tb.x = " << b.wsp_x() << "; b.y = " << b.wsp_y() << "\n"
                << "\tPunkt c:\n\t\tc.x = " << c.wsp_x() << "; c.y = " << c.wsp_y() << "\n";
}