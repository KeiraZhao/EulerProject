/*
 * lprime.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <stdint.h>

using namespace std;

const uint32_t THRESHOLD = 775146;

int main(int argc, char** argv) {
    uint32_t factor;
    uint64_t large_number = 600851475143;
    bool prime_flag[THRESHOLD+10];
    for (int i = 0; i < THRESHOLD; i++)
        prime_flag[i] = true;
    for (int i = 2; i < THRESHOLD; i++) {
        if (!prime_flag[i]) continue;
        for (int j = 2; i*j < THRESHOLD; j++)
            prime_flag[i*j] = false;
    }
    for (int i = THRESHOLD-1; i >= 2; i--) {
        if (prime_flag[i] && large_number % i == 0) {
            factor = i;
            break;
        }
    }
    cout << factor << endl;
    cout << large_number % factor << endl;
    return 0;
}
