#include "punkt.hpp"

#include <iostream>
#include <cmath>
#include <complex>

Punkt::Punkt() {
    x = 0.0;
    y = 0.0;
}

Punkt::Punkt(double a, double b) {
    x = a;
    y = b;
}

Punkt::~Punkt() {
    x = 0.0;
    y = 0.0;
}

double Punkt::wsp_x() {
    return x;
}

double Punkt::wsp_y() {
    return y;
}

void Punkt::przesuniecie(Wektor v) {
    x += v.wsp_A();
    y += v.wsp_B();
}

void Punkt::rotacja_punkt(Punkt p, double kat) {
    double s_kat = kat * M_PI / 180;
    x = cos(s_kat) * (x - p.wsp_x()) - sin(s_kat) * (y - p.wsp_y()) + p.wsp_x();
    y = sin(s_kat) * (x - p.wsp_x()) + cos(s_kat) * (y - p.wsp_y()) + p.wsp_y();
}

void Punkt::symetria_punkt(Punkt p) {
    this->rotacja_punkt(p, 180);
}

void Punkt::symetria_prosta(Prosta l) {
    std::complex<double> A(l.wsp_x1(), l.wsp_y1());
    std::complex<double> B(l.wsp_x2(), l.wsp_y2());
    std::complex<double> P(x, y);

    std::complex<double> Pt = P - A;
    std::complex<double> Bt = B - A;

    std::complex<double> Pr = Pt / Bt;

    std::complex<double> wynik = std::conj(Pr) * Bt + A;

    x = (double)(std::real(wynik));
    y = (double)(std::imag(wynik));
}

void Punkt::test() {
    std::cout << "Klasa Punkt:\n\t" << "x = " << x << " y = " << y << "\n";
}