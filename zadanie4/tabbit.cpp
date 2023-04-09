#include "tabbit.hpp"


tab_bit::tab_bit(int rozm) {
    dl = rozm;
    tab = new slowo[(dl + rozmiarSlowa - 1) / rozmiarSlowa];
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        tab[i] = 0;
    }
}

tab_bit::tab_bit(slowo tb) {
    dl = rozmiarSlowa;
    tab = new slowo[1];
    tab[0] = tb;
}

tab_bit::tab_bit(std::initializer_list<bool> l) {
    dl = l.size();
    tab = new slowo[(dl + rozmiarSlowa - 1) / rozmiarSlowa];
    int i = 0;
    for (auto it = l.begin(); it != l.end(); it++) {
        pisz(i, *it);
        i++;
    }
}

tab_bit::tab_bit(const tab_bit &tb) {
    dl = tb.dl;
    tab = new slowo[(dl + rozmiarSlowa - 1) / rozmiarSlowa];
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        tab[i] = tb.tab[i];
    }
}

tab_bit::tab_bit(tab_bit &&tb) {
    dl = tb.dl;
    tab = tb.tab;
    tb.dl = 0;
    tb.tab = nullptr;
}

tab_bit& tab_bit::operator=(const tab_bit &tb) {
    if (&tb != this) {
        dl = tb.dl;
        delete[] tab;
        tab = new slowo[(dl + rozmiarSlowa - 1) / rozmiarSlowa];
        for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
            tab[i] = tb.tab[i];
        }
    }
    return *this;
}

tab_bit& tab_bit::operator=(tab_bit &&tb) {
    if (&tb != this) {
        dl = tb.dl;
        tb.dl = 0;
        delete[] tab;
        tab = tb.tab;
        tb.tab = nullptr;
    }
    return *this;
}

tab_bit::~tab_bit() {
    dl = 0;
    delete[] tab;
}

bool tab_bit::czytaj(int i) const {
    if (i >= dl || i < 0) {
        throw std::out_of_range("Indeks poza zakresem");
    }

    int nr_slowa = i / rozmiarSlowa;
    int nr_bitu = i % rozmiarSlowa;
    return (tab[nr_slowa] >> nr_bitu) & 1ull;
}

bool tab_bit::pisz(int i, bool b) {
    if (i >= dl || i < 0) {
        throw std::out_of_range("Indeks poza zakresem");
    }
    int nr_slowa = i / rozmiarSlowa;
    int nr_bitu = i % rozmiarSlowa;
    int poprzednia_wartosc = (tab[nr_slowa] >> nr_bitu) & 1ull;
    if (b == 1) {
        tab[nr_slowa] |= (1ull << nr_bitu);
    }
    else { // b == 0
        tab[nr_slowa] &= ~(1ull << nr_bitu);
    }
    return poprzednia_wartosc;
}

bool tab_bit::operator[](int i) const {
    return czytaj(i);
}

tab_bit::ref tab_bit::operator[](int i) {
    ref result(*this, i);
    return result;
}

int tab_bit::rozmiar() const{
    return dl;
}

tab_bit tab_bit::operator|(const tab_bit &tb) const {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }
    tab_bit wynik(dl);
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        wynik.tab[i] = tab[i] | tb.tab[i];
    }
    return wynik;
}

tab_bit& tab_bit::operator|=(const tab_bit &tb) {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }

    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        tab[i] |= tb.tab[i];
    }

    return *this;
}

tab_bit tab_bit::operator&(const tab_bit &tb) const {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }
    tab_bit wynik(dl);
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        wynik.tab[i] = tab[i] & tb.tab[i];
    }
    return wynik;
}

tab_bit& tab_bit::operator&=(const tab_bit &tb) {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }

    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        tab[i] &= tb.tab[i];
    }

    return *this;
}

tab_bit tab_bit::operator^(const tab_bit &tb) const {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }
    tab_bit wynik(dl);
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        wynik.tab[i] = tab[i] ^ tb.tab[i];
    }
    return wynik;
}

tab_bit& tab_bit::operator^=(const tab_bit &tb) {
    if (tb.rozmiar() != dl) {
        throw std::invalid_argument("Tablice różnej długości");
    }

    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        tab[i] ^= tb.tab[i];
    }

    return *this;
}

tab_bit tab_bit::operator!() const {
    tab_bit wynik(dl);
    for (int i = 0; i < (dl + rozmiarSlowa - 1) / rozmiarSlowa; i++) {
        wynik.tab[i] = ~tab[i];
    }
    return wynik;
}

std::ostream& operator<<(std::ostream &os, const tab_bit &tb) {
    for (int i = 0; i < tb.rozmiar(); i++) {
        os << tb[i];
    }
    return os;
}

std::istream& operator>>(std::istream &is, tab_bit &tb) {
    char c;
    int i = 0;
    while (is.get(c)) {
        if (c == '\n' || c == ' ' || c == '\t') {
            continue;
        }
        else {
            is.unget();
            break;
        }
    }
    while (is.get(c) && i < tb.rozmiar()) {
        if (c =='0' || c == '1') {
            tb[i] = c - '0';
            i++;
        }
        else {
            is.unget();
            break;
        }
    }
    return is;
}