/*
 * lattice.cpp
 * Copyright (C) 2014-02-01 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char** argv) {
    int m, n;
    uint64_t prod = 1;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        prod *= m+i;
        prod /= i;
    }
    cout << prod << endl;
    return 0;
}

