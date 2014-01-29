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

using namespace std;

// Deterministic primality test, Wilson's theorem
// Complexity: O(2^n), where n = log p
bool is_prime_wilson(int p) {
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    int factorial = 1;
    for (int i = p-1; i >= 2; i--) {
        factorial *= i;
        factorial %= p;
    }
    return factorial == p-1;
}

// Deterministic primality test, naive algorithm
// Complexity: O(2^(n/2)) = O(2^n), where n = log p
bool is_prime_naive(int p) {
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    int sqroot = (int)(sqrt(p) + 1);
    for (int i = 2; i <= sqroot; i++) {
        if (p % i == 0) return false;
    }
    return true;
}

// Probabilistic primality test, Fermat's little theorem
// Complexity: O(n), where n = log p
bool is_prime_fermat(int p) {
    // 1 <= fermet_tester < p 
    // Let a = fermet_tester, if a^(p-1) \== 1 (mod p)
    // then p is a composite
    assert(p >= 0);
    if (p == 1) return false;
    if (p == 2) return true;
    mt19937 gen;
    uniform_int_distribution<int> dis(2, p-1);
    int fermat_tester = dis(gen);
    int base = fermat_tester, accmu = 1, power = p-1;
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




int main(int argc, char** argv) {
    int counter = 0;
    int n, p10001;
    cin >> n;
    for (int i=2; ; i++) {
        //cout << "current judging number = " << i << endl;
        //3 times Fermet-test and 1 time Wilson
        if (is_prime_fermat(i) && 
            is_prime_fermat(i) && 
            is_prime_fermat(i)) {
            counter++;
            cout << counter << ": " << i << endl;
        }
        if (counter == n) {
            p10001 = i;
            break;
        }
    }
    cout << p10001 << endl;
    return 0;
}






