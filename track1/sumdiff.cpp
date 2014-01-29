/*
 * sumdiff.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    cout << n * (n+1) * (n-1) * (3*n+2) / 12 << endl;
    return 0;
}
