#include "wektor.hpp"

Wektor::Wektor() {
    A = 0;
    B = 0;
}

Wektor::Wektor(double x, double y) {
    A = x;
    B = y;
}

Wektor::~Wektor() {
    A = 0;
    B = 0;
}

double Wektor::wsp_A() {
    return A;
}

double Wektor::wsp_B() {
    return B;
}