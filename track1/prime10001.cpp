/*
 * prime10001.cpp
 * Copyright (C) 2014-01-29 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include <random>
#include <vector>
#include <stdint.h>

using namespace std;

// Deterministic primality test, Wilson's theorem
// Complexity: O(2^n), where n = log p
bool is_prime_wilson(uint64_t p) {
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    int factorial = 1;
    for (uint64_t i = p-1; i >= 2; i--) {
        factorial *= i;
        factorial %= p;
    }
    return factorial == p-1;
}

// Deterministic primality test, naive algorithm
// Complexity: O(2^(n/2)) = O(2^n), where n = log p
bool is_prime_naive(uint64_t p) {
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    uint64_t sqroot = (uint64_t)(sqrt(p) + 1);
    for (uint64_t i = 2; i <= sqroot; i++) {
        if (p % i == 0) return false;
    }
    return true;
}

// Probabilistic primality test, Fermat's little theorem
// Complexity: O(n), where n = log p
bool is_prime_fermat(uint64_t p) {
    // 1 <= fermet_tester < p 
    // Let a = fermet_tester, if a^(p-1) \== 1 (mod p)
    // then p is a composite
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    mt19937 gen;
    uniform_int_distribution<uint64_t> dis(2, p-1);
    uint64_t fermat_tester = dis(gen);
    uint64_t base = fermat_tester, accmu = 1, power = p-1;
    assert(fermat_tester >= 2 && fermat_tester < p);
    while (power > 0) {
        if (power & 1) {
            accmu *= base;
            accmu %= p;
        }
        base *= base;
        base %= p;
        power >>= 1;
    }
    return accmu == 1;
}

// Return all the primes less than n
vector<uint64_t> prime_sieve(uint64_t n) {
    bool* prime = new bool[n+2];
    for (uint32_t i = 0; i < n; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (uint32_t i = 2; i < n+2; i++) {
        if (!prime[i])
            continue;
        for (int j = 2; i*j < n+2; j++) {
            prime[i*j] = false;
        }
    }
    vector<uint64_t> primes;
    for (uint32_t i = 2; i < n+2; i++) {
        if (prime[i])
            primes.push_back(i);
    }
    return primes;
}

bool basic_is_prime_test(vector<uint64_t> primes, uint64_t p) {
    // test for first 100
    auto iter = primes.begin();
    while (iter != primes.end() && p > *iter) {
        if (p % *iter == 0) {
            return false;
        }
        iter += 1;
    }
    return true;
}


int main(int argc, char** argv) {
    int counter = 0;
    uint64_t n, p10001;
    cin >> n;
    //vector<int> primes = prime_sieve(100);
    for (int i=2; ; i++) {
        ////cout << "current judging number = " << i << endl;
        ////3 times Fermet-test and 1 time Wilson
        ////cout << "current test: " << i << endl;
        //if (is_prime_fermat(i) && 
            //is_prime_fermat(i) && 
            //is_prime_fermat(i)) {
            //counter++;
            //cout << counter << ": " << i << endl;
        //}
        ////if (is_prime_wilson(i)) {
            ////counter++;
            ////cout << counter << ": " << i << endl;
        ////}
        if (counter == n) {
            p10001 = i;
            break;
        }
    }
    cout << p10001 << endl;
    return 0;
}


