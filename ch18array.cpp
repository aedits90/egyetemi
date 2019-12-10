// Chapter 18 Tömb Drill

#include <iostream>
#include <stdexcept>
//#include "std_lib_facilities.h"


// 1. global int ga array 10db a 2 hatványai 
int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int ar[], int n)
{
    int la[10] = { };
    for (int i=0; i<n; ++i) la[i] = ar[i];

    //Másol
    for (const auto& a : la)
        std::cout << a << ' ';
    std::cout << '\n';

    int* p = new int[n];
    for (int i=0; i<n; ++i) p[i] = ar[i];
    
    //Mutogat (a pointer a free store-ra)
    for (int i=0; i<n; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';

    delete[] p;
}

int faktorialis(int n) { return n > 1 ? n*faktorialis(n-1) : 1; }

int main()
try {
    f(ga, 10);

    int aa[10] = {};
    for (int i=0; i<10; ++i)
        aa[i] = faktorialis(i + 1);

    f(aa, 10);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}