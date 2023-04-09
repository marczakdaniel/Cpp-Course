#include <iostream>
#include "kolor.hpp"
#include "piksel.hpp"

int main() {
    /* Testy */

    Kolor k1 = Kolor(10, 12, 3);
    k1.test_kolor();
    k1.rozjasnij(10);
    k1.test_kolor();

    Kolortransparentny kt1 = Kolortransparentny(1, 2, 3, 4);
    kt1.test_kolortransparentny();

    Kolornazwany kn1 = Kolornazwany(10, 11, 12, "kn");
    kn1.test_kolornazwany();

    Kolornt knt1 = Kolornt(21, 22, 23, 24, "knt");
    knt1.test_kolornt();

    Piksel p1 = Piksel(10, 9);
    p1.test_piksel();

    Pikselkolorowy pk1 = Pikselkolorowy(89, 123, 7, 8, 9, 10);
    pk1.test_pikselkolorowy();

    std::cout << odleglosc(p1, pk1) << std::endl;
    std::cout << odleglosc(&p1, &pk1) << std::endl;
}