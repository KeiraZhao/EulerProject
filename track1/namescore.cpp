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
    sort(names.begin(), names.end());
    uint64_t scores = 0;
    for (int i = 0; i < names.size(); i++) {
        scores += (i+1) * score(names[i]);
    }
    cout << scores << endl;
    cout << score("COLIN") << endl;
    return 0;
}


