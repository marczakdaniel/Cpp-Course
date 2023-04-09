#include "f_glob.hpp"
#include <cmath>
#include <iostream>

bool double_equal(double w1, double w2) {
    const double EPSILON = 0.000001;
    if (std::abs(w1 - w2) < EPSILON) {
        return true;
    }
    return false;
}

double odleglosc(Punkt p, Punkt q) {
    return sqrt(pow(p.wsp_x() - q.wsp_x(), 2.0) + pow(p.wsp_y() - q.wsp_y(), 2.0));
}

bool czy_rownolegle(Odcinek l, Odcinek m) {
    Punkt l_a = l.pkt_a();
    Punkt l_b = l.pkt_b();
    Punkt m_a = m.pkt_a();
    Punkt m_b = m.pkt_b();

    double s1 = (l_a.wsp_x() - l_b.wsp_x()) / (l_a.wsp_y() - l_b.wsp_y());
    double s2 = (m_a.wsp_x() - m_b.wsp_x()) / (m_a.wsp_y() - m_b.wsp_y());
    if (double_equal(s1, s2)) return true;
    else return false;
}

bool czy_prostopadle(Odcinek l, Odcinek m) {
    Punkt l_a = l.pkt_a();
    Punkt l_b = l.pkt_b();
    Punkt m_a = m.pkt_a();
    Punkt m_b = m.pkt_b();

    double s1 = (l_a.wsp_x() - l_b.wsp_x()) / (l_a.wsp_y() - l_b.wsp_y());
    double s2 = (m_a.wsp_x() - m_b.wsp_x()) / (m_a.wsp_y() - m_b.wsp_y());
    double w = s1 * s2;
    if (double_equal(w, -1.0)) return true;
    else return false;
}

bool czy_zawiera(Trojkat e, Trojkat f) {
    Punkt e_x = e.pkt_a();
    Punkt e_y = e.pkt_b();
    Punkt e_z = e.pkt_c();

    Punkt f_x = f.pkt_a();
    Punkt f_y = f.pkt_b();
    Punkt f_z = f.pkt_c();

    if (e.czy_nalezy(f_x) && e.czy_nalezy(f_y) && e.czy_nalezy(f_z)) return true;
    else if (f.czy_nalezy(e_x) && f.czy_nalezy(e_y) && f.czy_nalezy(e_z)) return true;
    return false;
}

bool czy_rozlaczne(Trojkat e, Trojkat f) {
    Punkt e_x = e.pkt_a();
    Punkt e_y = e.pkt_b();
    Punkt e_z = e.pkt_c();

    Punkt f_x = f.pkt_a();
    Punkt f_y = f.pkt_b();
    Punkt f_z = f.pkt_c();

    if (e.czy_nalezy(f_x) || e.czy_nalezy(f_y) || e.czy_nalezy(f_z)) return false;
    else if (f.czy_nalezy(e_x) || f.czy_nalezy(e_y) || f.czy_nalezy(e_z)) return false;
    return true;
}