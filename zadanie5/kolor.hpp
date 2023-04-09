#ifndef KOLOR_HPP
#define KOLOR_HPP

#include <cstdint>
#include <string>

class Kolor {
    static Kolor mieszaj(Kolor a, Kolor b);
    protected:
        uint8_t R;  
        uint8_t G;
        uint8_t B;
    public:
        Kolor();
        Kolor(int r, int g, int b);
        uint8_t get_R();
        uint8_t get_G();
        uint8_t get_B();
        void set_R(int r);
        void set_G(int g);
        void set_B(int b);
        void rozjasnij(int x);
        void przyciemnij(int x);
        void test_kolor();
};

class Kolortransparentny : public virtual Kolor {
    protected:
        uint8_t alpha; 
    public:
        Kolortransparentny();
        Kolortransparentny(int r, int g, int b, int t);
        uint8_t get_alpha();       
        void set_alpha(int a);
        void test_kolortransparentny();
};

class Kolornazwany : public virtual Kolor {
    protected:
        std::string nazwa;
    public:
        Kolornazwany();
        Kolornazwany(int r, int g, int b, std::string a);
        std::string get_nazwa();
        void set_nazwa(std::string a);
        void test_kolornazwany();
};

class Kolornt 
    : public Kolortransparentny, public Kolornazwany {
    public:
        Kolornt();
        Kolornt(int r, int g, int b, int t, std::string a);
        void test_kolornt();
};
 
#endif // KOLOR_HPP