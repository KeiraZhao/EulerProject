/*
 * evenfib.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

const int THRESHOLD = 4000000;

int main(int argc, char** argv) {
    int sum = 0;
    int fib1 = 1, fib2 = 2;
    while (true) {
        if (fib1 > THRESHOLD) break;
        if (fib1 % 2 == 0) sum += fib1;
        if (fib2 % 2 == 0 && fib2 <= THRESHOLD) sum += fib2;
        fib1 += fib2;
        fib2 += fib1;
    }
    cout << sum << endl;
    return 0;
}
