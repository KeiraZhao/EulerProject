/*
 * firstfib.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string bigsum(const string& s1, const string& s2) {
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
    for (int i = 0; i < sums.length(); i++) {
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

int main(int argc, char** argv) {
    string s1 = "1", s2 = "1";
    int power_times = 0;
    int n;
    cin >> n;
    while (power_times++ < n) {
        s1 = bigsum(s1, s2);
        s2 = s1;
    }
    int digits_sum = 0;
    for (int i = 0; i < s2.length(); i++)
        digits_sum += s2[i] - '0';
    cout << digits_sum << endl;
    cout << "-------------------------------" << endl;
    cout << s2 << endl;
    return 0;
}

