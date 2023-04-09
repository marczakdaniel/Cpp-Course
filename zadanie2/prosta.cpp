#include "prosta.hpp"
#include <stdexcept>

Prosta::Prosta(double x1, double y1, double x2, double y2) {
    if (x1 == x2 && y1 == y2) {
        throw std::invalid_argument("nie można utworzyć odcinka z jednego punktu");
    }
    else {
        X1 = x1;
        Y1 = y1;
        X2 = x2;
        Y2 = y2;
    }
}

Prosta::~Prosta() {
    X1 = 0;
    Y1 = 0;
    X2 = 0;
    Y2 = 0;
}

double Prosta::wsp_x1() {
    return X1;
}

double Prosta::wsp_y1() {
    return Y1;
}

double Prosta::wsp_x2() {
    return X2;
}

double Prosta::wsp_y2() {
    return Y2;
}