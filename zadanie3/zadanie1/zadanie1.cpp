#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

const vector<pair<int, string>> rzym = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

string bin2rzym(int x) {
    int pos = 0;
    string result = "";
    while (x > 0) {
        if (rzym[pos].first <= x) {
            int num = x / rzym[pos].first;
            x %= rzym[pos].first;
            while(num--) {
                result += rzym[pos].second;
            }
        }
        pos++;
    }
    return result;
}

int main(int argc, char **argv) {
    for (int t = 1; t < argc; t++) {
        string s = argv[t];
        int bin = 0;
        try {
            bin = stoi(s, nullptr, 10);
            if (bin > 3999 || bin < 1) {
                clog << "Out of Range (1 - 3999): " << bin << "\n";
            }
            else {
                cout << bin2rzym(bin) << "\n";
            }
        }
        catch (const invalid_argument& ia) {
            clog << "Invalid argument: " << ia.what() << "\n";
        }
        catch (const out_of_range& oor) {
            clog << "Out of Range error: " << oor.what() << '\n';
        }
    }
}