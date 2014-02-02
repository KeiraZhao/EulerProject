/*
 * maxspath.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>

using namespace std;

// Maximum sum path, dynamic programming
int main(int argc, char** argv) {
    int matrix[100][100], sums[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> matrix[i][j];
        }
    }
    // buttom-up approach
    for (int i = 0; i < 100; i++) {
        sums[99][i] = matrix[99][i];
    }
    for (int i = 98; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            sums[i][j] = sums[i+1][j] > sums[i+1][j+1] ? sums[i+1][j] : sums[i+1][j+1];
            sums[i][j] += matrix[i][j];
        }
    }
    cout << sums[0][0] << endl;
    return 0;
}

