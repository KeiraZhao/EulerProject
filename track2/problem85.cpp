/*
 * problem85.cpp
 * Copyright (C) 2014-02-07 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char ** argv) {
    int n = 8e6;
    int min_dist = 1e6;
    int x, y;
    for (int a = 5; a <= 1000; a++) {
        for (int b = 5; b <= 1000; b++) {
            int tmp = a * (a+1) * b * (b+1);
            if (abs(tmp - n) < min_dist) {
                min_dist = abs(tmp-n);
                x = a;
                y = b;
            }
        }
    }
    cout << x * y << endl;
    cout << x << "," << y << endl;
    cout << x * (x+1) * y * (y+1) << endl;
    return 0;
}
