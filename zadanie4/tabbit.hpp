#ifndef TABBIT_HPP
#define TABBIT_HPP

#include <iostream>


class tab_bit {
    typedef uint64_t slowo;        // komorka w tablicy
    static const int rozmiarSlowa = 8 * sizeof(slowo); // rozmiar slowa w bitach
    friend std::istream &operator>>(std::istream &we, tab_bit &tb);
    friend std::ostream &operator<<(std::ostream &wy, const tab_bit &tb);
    class ref {
        private:
            tab_bit &t;
            int idx;
        public:
            ref(tab_bit &t, int idx) : t(t), idx(idx) {}
            ref& operator=(bool b) {
                t.pisz(idx, b);
                return *this;
            }
            ref& operator=(ref &r) {
                t.pisz(idx, r);
                return *this;
            }
            operator bool() const {
                return t.czytaj(idx);
            }
    }; // klasa pomocnicza do adresowania bitów

    protected:
        int dl;     // liczba bitów
        slowo *tab; // tablica bitów
    public:
        explicit tab_bit(int rozm); // wyzerowana tablica bitow [0...rozm]
        explicit tab_bit(slowo tb); // tablica bitów [0...rozmiarSlowa]
                                    // zainicjalizowana wzorcem
        tab_bit(std::initializer_list<bool> l);
        tab_bit(const tab_bit &tb);            // konstruktor kopiujący
        tab_bit(tab_bit &&tb);                 // konstruktor przenoszący
        tab_bit &operator=(const tab_bit &tb); // przypisanie kopiujące
        tab_bit &operator=(tab_bit &&tb);      // przypisanie przenoszące
        ~tab_bit();                            // destruktor
    private:
        bool czytaj(int i) const; // metoda pomocnicza do odczytu bitu
        bool pisz(int i, bool b); // metoda pomocnicza do zapisu bitu
    public:
        bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
        ref operator[](int i);        // indeksowanie dla zwykłych tablic bitowych
        inline int rozmiar() const;   // rozmiar tablicy w bitach
    public:
        // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
        tab_bit operator|(const tab_bit &tb) const;
        tab_bit& operator|=(const tab_bit &tb);
        tab_bit operator&(const tab_bit &tb) const;
        tab_bit& operator&=(const tab_bit &tb);
        tab_bit operator^(const tab_bit &tb) const;
        tab_bit& operator^=(const tab_bit &tb);
        tab_bit operator!() const;
    public:
        // zaprzyjaźnione operatory strumieniowe: << i >>
        friend std::ostream &operator<<(std::ostream &os, const tab_bit &tb);
        friend std::istream &operator>>(std::istream &is, tab_bit &tb);
};

#endif // TABBIT_HPP