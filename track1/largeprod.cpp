/*
 * largeprod.cpp
 * Copyright (C) 2014-02-01 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int matrix[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> matrix[i][j];
        }
    }
    int max_prod = 1;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            int horizontal_prod = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
            int vertical_prod = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
            int diagonal_prod = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
            max_prod = horizontal_prod > max_prod ? horizontal_prod : max_prod;
            max_prod = vertical_prod > max_prod ? vertical_prod : max_prod;
            max_prod = diagonal_prod > max_prod ? diagonal_prod : max_prod;
        }
    }
    for (int i = 19; i >= 3; i--) {
        for (int j = 0; j < 17; j++) {
            int diagonal_prod = matrix[i][j] * matrix[i-1][j+1] * matrix[i-2][j+2] * matrix[i-3][j+3];
            max_prod = diagonal_prod > max_prod ? diagonal_prod : max_prod;
        }
    }
    cout << max_prod << endl;
    return 0;
}

