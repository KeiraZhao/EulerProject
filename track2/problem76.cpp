/*
 * problem76.cpp
 * Copyright (C) 2014-02-15 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int N = 100;
    int array[110][110];
    int brray[110][110];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            array[i][j] = 0;
            brray[i][j] = 0;
        }
    brray[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        array[i][i] = 1;
    }
    // Bottom-up 2 dimensional DP, O(N^2)
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j < i; j++) {
            array[i][j] = brray[i-j][j];
            brray[i][j] = brray[i][j-1] + array[i][j];
        }
        for (int j = i; j <= N; j++)
            brray[i][j] = brray[i][j-1] + array[i][j];
    }
    cout << brray[100][99] << endl;
}
