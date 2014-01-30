/*
 * triple.cpp
 * Copyright (C) 2014-01-30 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    for (int a = 1; a < 1000; a++) {
        for (int b = a; b < 1000; b++) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                cout << "Valid solution: " << a << ',' << b << ',' << c << endl;
                cout << a * b * c << endl;
            }
        }
    }

    return 0;

}
