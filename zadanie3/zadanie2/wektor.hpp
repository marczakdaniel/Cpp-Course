#ifndef WEKTOR_HPP
#define WEKTOR_HPP

class Wektor {
    private:
        double A;
        double B;
    public:
        Wektor();
        Wektor(double x, double y);
        ~Wektor();

        double wsp_A();
        double wsp_B();
};

#endif // WEKTOR_HPP