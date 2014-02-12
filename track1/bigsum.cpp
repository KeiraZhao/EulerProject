/*
 * bigsum.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include "bigsum.h"
#include <iostream>


using namespace std;

string bigsum(const string& s1, const string& s2) {
    if (s1.length() < s2.length())
        return rbigsum(s1, s2);
    else 
        return rbigsum(s2, s1);
}

string rbigsum(const string& s1, const string& s2) {
    // assuming s1 <= s2;
    string as1 = s1, as2 = s2;
    reverse(as1.begin(), as1.end());
    reverse(as2.begin(), as2.end());
    int diff = as2.length() - as1.length();
    for (int i = 0; i < diff; i++)
        as1 += "0";
    for (int i = 0; i < as1.length(); i++) as1[i] -= '0';
    for (int i = 0; i < as2.length(); i++) as2[i] -= '0';
    string sums(as2.length() + 1, 0);
    for (int i = 0; i < as2.length(); i++)
        sums[i] = as1[i] + as2[i];
    for (int i = 1; i < sums.length(); i++) {
        sums[i] += sums[i-1] / 10;
        sums[i-1] %= 10;
    }
    if (!sums[sums.length()-1]) 
        sums.pop_back();
    for (int i = 0; i < sums.length(); i++)
        sums[i] += '0';
    reverse(sums.begin(), sums.end());
    return sums;
}

string bigprod(const string& s1, const string& s2) {
    if (s1.length() > s2.length())
        return rbigprod(s1, s2);
    else 
        return rbigprod(s2, s1);
}

string rbigprod(const string& s1, const string& s2) {
    //cout << "Inside big product: " << endl;
    int** partial_sum = new int*[s2.length()];
    for (int i = 0; i < s2.length(); i++)
        partial_sum[i] = new int[s1.length() + s2.length()];
    // Initialize
    for (int i = 0; i < s2.length(); i++) {
        for (int j = 0; j < s1.length() + s2.length(); j++) {
            partial_sum[i][j] = 0;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        int digit = s2[s2.length()-1-i]-'0';
        for (int j = i; j < s1.length()+i; j++)
            partial_sum[i][j] = (s1[s1.length()-1-j+i]-'0') * digit;
    }
    int* sums = new int[s1.length() + s2.length()];
    for (int i = 0; i < s2.length(); i++) {
        for (int j = 0; j < s1.length() + s2.length(); j++) {
            sums[j] += partial_sum[i][j];
        }
    }
    for (int i = 1; i < s1.length() + s2.length(); i++) {
        sums[i] += sums[i-1] / 10;
        sums[i-1] %= 10;
    }
    int end = s1.length() + s2.length();
    if (sums[s1.length() + s2.length() - 1] == 0)
        end -= 1;
    string prod_sum;
    for (int i = end-1; i >= 0; i--) {
        prod_sum += sums[i] + '0';
    }
    return prod_sum;
}

vector<uint32_t> primes_generator(uint32_t range) {
    bool* flag = new bool[range+1];
    for (int i = 0; i <= range; i++) {
        flag[i] = true;
    }
    flag[0] = flag[1] = false;
    for (int i = 2; i <= range; i++) {
        if (!flag[i]) 
            continue;
        for (int j = 2; j*i <= range; j++) {
            flag[i*j] = false;
        }
    }
    vector<uint32_t> primes;
    for (int i = 2; i <= range; i++) {
        if (flag[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}





