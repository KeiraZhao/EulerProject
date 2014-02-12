/*
 * selfpower.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <stdint.h>

using namespace std;

const uint64_t BASE = 10000000000;

uint64_t powermod(uint64_t n) {
    uint64_t prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= n;
        prod %= BASE;
    }
    return prod;
}


int main(int argc, char** argv) {
    uint32_t n;
    uint64_t last_digits = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        last_digits += powermod(i);
        last_digits %= BASE;
    }
    cout << last_digits << endl;
    return 0;
}

