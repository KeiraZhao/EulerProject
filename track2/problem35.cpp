/*
 * problem35.cpp
 * Copyright (C) 2014-02-13 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool prime_test(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool basic_judge(int n) {
    int iter = 0;
    int array[10];
    while (n > 0) {
        array[iter++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < iter; i++) {
        if (array[i] % 2 == 0)
            return false;
        if (array[i] % 5 == 0)
            return false;
    }
    int sum = 0;
    for (int i = 0; i < iter; i++) 
        sum += array[i];
    return sum % 3 != 0;
}

vector<int> compute_variants(int n) {
    vector<int> variants;
    int iter = 0;
    int array[10];
    while (n > 0) {
        array[iter++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < iter/2; i++) {
        array[i] ^= array[iter-i-1];
        array[iter-i-1] ^= array[i];
        array[i] ^= array[iter-i-1];
    }
    for (int i = 0; i < iter; i++) {
        int current = 0;
        for (int j = 0; j < iter; j++) {
            current *= 10;
            current += array[(i+j) % iter];
        }
        variants.push_back(current);
    }
    return variants;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (!prime_test(i)) 
            continue;
        vector<int> variants = compute_variants(i);
        bool flag = true;
        for (int j = 0; j < variants.size(); j++) {
            if (!prime_test(variants[j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
            tot++;
        }
    }
    cout << "---------------------------" << endl;
    cout << tot << endl;
    return 0;
}
