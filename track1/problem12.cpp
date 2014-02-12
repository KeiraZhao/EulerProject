/*
 * problem12.cpp
 * Copyright (C) 2014-02-04 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include "bigsum.h"
#include <iostream>
#include <cassert>

using namespace std;

int compute_divisors(int n, vector<uint32_t> primes) {
    assert(n >= 1);
    vector<uint32_t> factors(primes.size(), 0);
    for (int i = 0; i < primes.size(); i++) {
        int count = 0;
        while (n % primes[i] == 0) {
            count++;
            n /= primes[i];
        }
        factors[i] = count;
    }
    int all_divisors = 1;
    for (int i = 0; i < primes.size(); i++) {
        all_divisors *= (factors[i] + 1);
    }
    return all_divisors;
}

int main(int argc, char** argv) {
    int range = 1000;
    vector<uint32_t> primes = primes_generator(range);
    int n = 1;
    while (true) {
        int sqr_number = n * (n+1) / 2;
        int divisor_count = compute_divisors(sqr_number, primes);
        cout << "n: " << sqr_number << ", divisors: " << compute_divisors(sqr_number, primes) << endl;
        if (divisor_count > 500) {
            break;
        }
        n++;
    }
    return 0;
}

