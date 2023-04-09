#ifndef F_GLOBAL_HPP
#define F_GLOBAL_HPP

#include "punkt.hpp"
#include "odcinek.hpp"
#include "trojkat.hpp"

bool double_equal(double w1, double w2);

double odleglosc(Punkt p, Punkt q);

bool czy_rownolegle(Odcinek l, Odcinek m);

bool czy_prostopadle(Odcinek l, Odcinek m);

bool czy_rozlaczne(Trojkat e, Trojkat f);

bool czy_zawiera(Trojkat e, Trojkat f);
#endif // F_GLOBAL_HPP