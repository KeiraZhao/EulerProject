/*
 * sumprime.cpp
 * Copyright (C) 2014-01-30 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <stdint.h>

using namespace std;


int main(int argc, char** argv) {
    const int BOUND = 2000000;
    bool* prime_indicator = new bool[BOUND+10];
    for (int i = 2; i <= BOUND; i++) {
        prime_indicator[i] = true;
    }
    // Sieve
    for (int i = 2; i <= BOUND; i++) {
        if (!prime_indicator[i])
            continue;
        for (int j = 2; i*j <= BOUND; j++) {
            prime_indicator[i*j] = false;
        }
    }
    uint64_t prime_sums = 0;
    for (int i = 2; i <= BOUND; i++) {
        if (prime_indicator[i]) {
            prime_sums += i;
        }
    }
    cout << prime_sums << endl;
    return 0;
}
