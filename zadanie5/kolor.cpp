#include "kolor.hpp"

#include <stdexcept>
#include <algorithm>
#include <iostream>

Kolor::Kolor() {
    R = 0;
    G = 0;
    B = 0;
}

Kolor::Kolor(int r, int g, int b) {
    if (r > 255 || r < 0 || 
            g > 255 || g < 0 || 
            b > 255 || b < 0) {
        
        throw std::invalid_argument("Invalid argument");
    }
    R = r;
    G = g;
    B = b;
}

uint8_t Kolor::get_R() {
    return R;
}

uint8_t Kolor::get_G() {
    return G;
}

uint8_t Kolor::get_B() {
    return B;
}

void Kolor::set_R(int r) {
    if (r > 255 || r < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    R = r;
}

void Kolor::set_G(int g) {
    if (g > 255 || g < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    G = g;
}

void Kolor::set_B(int b) {
    if (b > 255 || b < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    B = b;
}

void Kolor::rozjasnij(int x) {
    if (x < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    R = std::min(255, (int)R + x);
    G = std::min(255, (int)G + x);
    B = std::min(255, (int)B + x);
}

void Kolor::przyciemnij(int x) {
    if (x < 0) {
        throw std::invalid_argument("Invalid argument");
    }
    R = std::max(0, (int)R - x);
    G = std::max(0, (int)G - x);
    B = std::max(0, (int)B - x);
}

Kolor Kolor::mieszaj(Kolor a, Kolor b) {
    Kolor w = Kolor();
    w.set_B(((int)a.get_B() + (int)b.get_B()) / 2);
    w.set_R(((int)a.get_R() + (int)b.get_R()) / 2);
    w.set_G(((int)a.get_G() + (int)b.get_G()) / 2);
    return w;
}

void Kolor::test_kolor() {
    std::cout << "Kolor::  R: " << (int)R << " G: " << (int)G << " B: " << (int)B << std::endl;
}

Kolortransparentny::Kolortransparentny() : Kolor() {
    alpha = 0;
}

Kolortransparentny::Kolortransparentny(int r, int g, int b, int t) : Kolor(r, g, b) {
    if (t < 0 || t > 255) {
        throw std::invalid_argument("Invalid argument");
    }
    alpha = t;
}

uint8_t Kolortransparentny::get_alpha() {
    return alpha;
}

void Kolortransparentny::set_alpha(int t) {
    if (t < 0 || t > 255) {
        throw std::invalid_argument("Invalid argument");
    }
    alpha = t;
}
void Kolortransparentny::test_kolortransparentny() {
    std::cout << "Kolortransparentny::  R: " << (int)R << " G: " << (int)G << " B: " << (int)B 
            << " alpha: " << (int)alpha << std::endl;
}

Kolornazwany::Kolornazwany() : Kolor() {
    nazwa = "";
}

std::string Kolornazwany::get_nazwa() {
    return nazwa;
}
void Kolornazwany::set_nazwa(std::string a) {
    nazwa = a;
}

Kolornazwany::Kolornazwany(int r, int g, int b, std::string a) : Kolor(r, g, b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 'z' || a[i] < 'a') {
            throw std::invalid_argument("Invalid argument");
        }
    }
    nazwa = a;
}

void Kolornazwany::test_kolornazwany() {
    std::cout << "Kolornazwany::  R: " << (int)R << " G: " << (int)G << " B: " << (int)B 
            << " nazwa: " << nazwa << std::endl;
}

Kolornt::Kolornt() : Kolortransparentny(), Kolornazwany() {};

Kolornt::Kolornt(int r, int g, int b, int t, std::string a) : Kolor(r, g, b) {
    if (t < 0 || t > 255) {
        throw std::invalid_argument("Invalid argument");
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 'z' || a[i] < 'a') {
            throw std::invalid_argument("Invalid argument");
        }
    }
    alpha = t;
    nazwa = a;
}

void Kolornt::test_kolornt() {
    std::cout << "Kolornt::  R: " << (int)R << " G: " << (int)G << " B: " << (int)B 
            << " alpha: " << (int)alpha << " nazwa: " << nazwa << std::endl;
}