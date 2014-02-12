/*
 * problem20.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include "bigsum.h"

using namespace std;

int main(int argc, char** argv) {
    //string s1, s2;
    //cin >> s1 >> s2;
    //cout << bigprod(s1, s2) << endl;
    string ans = "1";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans = bigprod(ans, to_string(i));
    }
    int digit_sum = 0;
    for (int i = 0; i < ans.length(); i++)
        digit_sum += ans[i]-'0';
    cout << digit_sum << endl;
    return 0;
}

