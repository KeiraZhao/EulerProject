/*
 * multiple35.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    int upperbound, sum = 0;
    cin >> upperbound;
    for (int i = 1; i < upperbound; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum << endl;
    return 0;
}
