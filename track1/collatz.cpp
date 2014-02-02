/*
 * collatz.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <stdint.h>
#include <cassert>
#include <cmath>

using namespace std;
    
const int MAXN = 1000001;
int times[MAXN];

int filling(uint64_t n) {
    if (n < MAXN && times[n])
        return times[n];
    else if (n < MAXN) {
        if (n % 2) {
            times[n] = filling(3*n+1) + 1;
            return times[n];
        } else {
            times[n] = filling(n/2) + 1;
            return times[n];
        }
    } else {
        if (n % 2) {
            return filling(3*n+1) + 1;
        } else {
            return filling(n/2) + 1;
        }
    }
}

void collatz(uint64_t n) {
    cout << n << ", ";
    if (n != 1 && n % 2) 
        collatz(3*n+1);
    else if (n % 2 == 0)
        collatz(n/2);
}

int collatz_steps(double n) {
    int count = 1;
    while (abs(n-1) > 1e-6) {
        count++;
        int intn = (int)n;
        if (intn % 2)
            n = 3*n + 1;
        else 
            n = n/2;
    }
    return count;
}

int main(int argc, char** argv) {
    for (int i = 0; i < MAXN; i++)
        times[i] = 0;
    times[1] = 1;
    for (uint64_t i = 1; i < MAXN; i++) {
        filling(i);
    }
    int max_step = 0, max_number = -1;
    for (int i = 1; i < MAXN; i++) {
        if (times[i] > max_step) {
            max_number = i;
            max_step = times[i];
        }
    }
    cout << max_step << endl;
    cout << max_number << endl;
    return 0;
}



