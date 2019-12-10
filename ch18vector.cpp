//Chapter 18 Vektor Drill

//#include "std_lib_facilities.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v)
{
    vector<int> lv(10);
    lv = v;
    for (auto& a : lv)
        cout << a << '\t';
    cout << '\n';

    vector<int> lv2 = v;
    for (auto& a : lv2)
        cout << a << '\t';
    cout << '\n';
}
int faktorialis(int n) { return n > 1 ? n*faktorialis(n-1) : 1; }

int main()
try {

    f(gv);

    vector<int> vv(10);
    for (int i=0; i<vv.size(); ++i)
        vv[i] = faktorialis(i + 1);
    f(vv);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}