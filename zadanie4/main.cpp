#include "tabbit.hpp"

using namespace std;

int main() {
    tab_bit t(46); // tablica 46-bitowa (zainicjalizowana zerami)
    tab_bit u((uint64_t)45); // tablica 64-bitowa (sizeof(uint64_t)*8)
    tab_bit v(t); // tablica 46-bitowa (skopiowana z t)
    tab_bit w(tab_bit{1, 0, 1, 1, 0, 0, 0, 1}); // tablica 8-bitowa (przeniesiona)
    v[0] = 1; // ustawienie bitu 0-go bitu na 1
    t[45] = true; // ustawienie bitu 45-go bitu na 1
    bool b = v[1]; // odczytanie bitu 1-go
    cout << u[45] << endl;
    u[63] = 1;
    u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
    cout << u[45] << endl;
    tab_bit z((uint64_t)254);
    cout<<w<<endl; // wysietlenie zawartości tablicy bitów na ekranie
    tab_bit T(5), Z(5);
    cin >> T >> Z;
    cout << T << " " << !Z << endl;
    cout << (T | Z) << endl;
    cout << (T & Z) << endl;
    tab_bit O({1, 0, 1, 1, 0, 0, 1});
    cout << "O:\n" << O << endl;
    O |= tab_bit{1, 1, 0, 0, 0, 0, 0};
    cout << O << endl;
    O &= tab_bit{1, 0, 1, 1, 1, 0, 0};
    cout << O << endl;
    O ^= tab_bit{1, 0, 0, 0, 1, 1, 1};
    cout << O << endl;
}