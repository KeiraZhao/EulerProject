/*
 * problem38.cpp
 * Copyright (C) 2014-02-15 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    bool flag[10];
    for (int i = 5000; i <= 9999; i++) {
        int first = i, second = 2 * i;
        for (int j = 0; j < 10; j++)
            flag[j] = false;
        while (first > 0) {
            flag[first % 10] = true;
            first /= 10;
        }
        while (second > 0) {
            flag[second % 10] = true;
            second /= 10;
        }
        bool is_valid = true;
        for (int j = 1; j < 10; j++)
            is_valid = is_valid && flag[j];
        if (is_valid)
            cout << i << endl;
    }

}
