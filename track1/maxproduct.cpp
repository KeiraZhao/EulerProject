/*
 * maxproduct.cpp
 * Copyright (C) 2014-01-30 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cerr << "Opening fail..." << endl;
        return -1;
    }
    int max_product = 1, consec_product = 1;
    string digits, line;
    while (fin >> line) {
        digits += line;
    }
    for (int i = 0; i < digits.length(); i++) {
        digits[i] -= '0';
    }
    for (int i = 0; i < digits.length()-4; i++) {
        consec_product = digits[i] * digits[i+1] * digits[i+2] * digits[i+3] * digits[i+4];
        if (consec_product > max_product) {
            max_product = consec_product;
        }
    }
    cout << max_product << endl;
    return 0;
} 
