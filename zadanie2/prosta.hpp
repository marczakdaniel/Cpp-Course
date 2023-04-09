#ifndef PROSTA_HPP
#define PROSTA_HPP

class Prosta {
    private:
        double X1;
        double X2;
        double Y1;
        double Y2;
    public:
        Prosta(double x1, double y1, double x2, double y2);
        ~Prosta();

        double wsp_x1();
        double wsp_y1();
        double wsp_x2();
        double wsp_y2();
};

#endif // PROSTA_HPP
