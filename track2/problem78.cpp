/*
 * problem76.cpp
 * Copyright (C) 2014-02-15 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <vector>

using namespace std;

// Euler's Generating function approach, even faster than DP
int M = 1000000;

int main(int argc, char** argv) { 
    vector<int> p;
    p.push_back(1);
    int n = 1, m;
    int coeff1, coeff2;
    int sign, pn;
    while (true) {
        m = 0;
        pn = 0;
        while (true) {
            m++;
            coeff1 = m * (3*m-1) / 2;
            coeff2 = -m * (-3*m-1) / 2;
            sign = m % 2 ? 1 : -1;
            if (coeff1 > n) break;
            pn += sign * p[n-coeff1];
            if (coeff2 > n) break;
            pn += sign * p[n-coeff2];
        }
        p.push_back(pn % 1000000);
        if (pn % 1000000 == 0)
            break;
        n++;
    }
    cout << n << endl;
    return 0;
}
