#ifndef PIKSEL_HPP
#define PIKSEL_HPP

#include "kolor.hpp"

class Piksel {
    protected:
        int x;
        int y;
    public:
        static const int ekran_x = 1920;
        static const int ekran_y = 1080;
        Piksel();
        Piksel(int a, int b);
        int od_lewej() const;
        int od_prawej() const;
        int od_gornej() const;
        int od_dolnej() const;
        void test_piksel();
};

class Pikselkolorowy : public Piksel {
    protected:
        Kolortransparentny kolor;
    public:
        Pikselkolorowy();
        Pikselkolorowy(int x1, int y1, int r, int g, int b, int t);
        void przemiesc(int a, int b);
        void test_pikselkolorowy();
};

int odleglosc(const Piksel &p, const Piksel &q);
int odleglosc(const Piksel *p, const Piksel *q);

#endif // PIKSEL_HPP