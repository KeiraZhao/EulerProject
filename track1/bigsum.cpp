/*
 * bigsum.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include "bigsum.h"

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

