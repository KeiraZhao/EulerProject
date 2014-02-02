/*
 * namescore.cpp
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <cmath>

using namespace std;

int score(const string& name) {
    int sum = 0;
    for (int i = 0; i < name.length(); i++)
        sum += name[i] - 'A' + 1;
    return sum;
}

int main(int argc, char** argv) {
    string input;
    cin >> input;
    vector<string> names;
    // parsing
    for (int i = 0; i < input.length();) {
        int j = i+1;
        if (input[i] == '\"') {
            while (input[j++] != '\"');
            names.push_back(string(input, i+1, j-i-2));
        }
        i = j;
    }
    int count = 0;
    for (const string& word : names) {
        int value = score(word) * 2;
        int sqroot = (int)sqrt(value);
        if (sqroot * (sqroot+1) == value ||
            (sqroot+1) * (sqroot+2) == value)
            count++;
    }
    cout << count << endl;
    return 0;
}


