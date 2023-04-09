#include "piksel.hpp"

#include <stdexcept>
#include <cmath>
#include <iostream>

Piksel::Piksel() {
    x = 0;
    y = 0;
}

Piksel::Piksel(int a, int b) {
    if (a > ekran_x || a < 0 || b > ekran_y || b < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    x = a;
    y = b;
}

int Piksel::od_lewej() const {
    return x;
}

int Piksel::od_prawej() const {
    return ekran_x - x;
}

int Piksel::od_gornej() const {
    return ekran_y - y;
}

int Piksel::od_dolnej() const {
    return y;
}

void Piksel::test_piksel() {
    std::cout << "Piksel:: x: " << (int)x << " y: " << (int)y << std::endl;
}

Pikselkolorowy::Pikselkolorowy() : Piksel() {
    kolor = Kolortransparentny();
}

Pikselkolorowy::Pikselkolorowy(int x1, int y1, int r, int g, int b, int t) : Piksel(x1, y1) {
    kolor = Kolortransparentny(r, g, b, t);
}

void Pikselkolorowy::przemiesc(int a, int b) {
    if (x + a > ekran_x || x + a < 0 || y + b > ekran_y || y + b < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    x += a;
    y += b;
}

void Pikselkolorowy::test_pikselkolorowy() {
    std::cout << "Pikselkolorowy:: x: " << (int)x << " y: " << (int)y << std::endl;
    std::cout << "\t";
    kolor.test_kolortransparentny();
}

int odleglosc(const Piksel &p, const Piksel &q) {
    int x1 = p.od_lewej();
    int x2 = q.od_lewej();
    int y1 = p.od_dolnej();
    int y2 = q.od_dolnej();
    int wynik = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return wynik;
}

int odleglosc(const Piksel *p, const Piksel *q) {
    int x1 = p->od_lewej();
    int x2 = q->od_lewej();
    int y1 = p->od_dolnej();
    int y2 = q->od_dolnej();
    int wynik = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return wynik;
}