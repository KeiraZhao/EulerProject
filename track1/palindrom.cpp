/*
 * palindrom.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

int six_digits(int a, int b, int c) {
    int sum = 9091 * a + 910 * b + 100 * c;
    for (int i = 10; i <= 90; i++) {
        if (sum % i == 0 && sum / i >= 100 && sum / i <= 999) 
            return i;
    }
    return -1;
}

bool five_digits(int a, int b, int c) {
    

}

int main(int argc, char** argv) {
    int t;
    for (int a = 9; a >= 1; a--) 
        for (int b = 9; b >= 0; b--)
            for (int c = 9; c >= 0; c--) {
                if ((t = six_digits(a, b, c)) > 0) {
                    cout << a << b << c << c << b << a << endl;
                    cout << t << endl;
                    return 0;
                }
            }
}
