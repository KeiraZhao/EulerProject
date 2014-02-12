/*
 * problem36.cpp
 * Copyright (C) 2014-02-05 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

bool is_panlindromic(int n, int base) {
    int* bin_rep = new int[32];
    int length = 0;
    while (n > 0) {
        bin_rep[length++] = n % base;
        n /= base;
    }
    for (int i = 0; i < length; i++) {
        if (bin_rep[i] != bin_rep[length-1-i])
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if (is_panlindromic(i, 10) && is_panlindromic(i, 2)) {
            cout << i << endl;
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
