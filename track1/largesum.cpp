/*
 * largesum.cpp
 * Copyright (C) 2014-01-29 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    vector<string> large_numbers;
    ifstream fin;
    string line;
    fin.open(argv[1]);
    if (!fin) {
        cerr << "Opening failed..." << endl;
        return -1;
    }
    while (fin >> line) {
        reverse(line.begin(), line.end());
        large_numbers.push_back(line);
    }
    auto iter = large_numbers.begin();
    while (iter != large_numbers.end()) {
        string l(iter->rbegin(), iter->rend());
        cout << l << endl;
        iter += 1;
    }
    cout << "----------------------------------" << endl;
    uint32_t number_length = line.length();
    int* answer = new int[number_length+100];
    // summing per bit
    for (int i = 0; i < number_length; i++) {
        auto iter = large_numbers.begin();
        while (iter != large_numbers.end()) {
            answer[i] += (*iter)[i] - '0';
            iter += 1;
        } 
    }
    for (int i = 1; i < number_length+100; i++) {
        answer[i] += answer[i-1] / 10;
        answer[i-1] %= 10;
    }
    int real_length = -1;
    for (int i = number_length+99; i >= 0; i--) {
        if (answer[i] > 0) {
            real_length = i+1;
            break;
        }
    }
    int* display_answer = new int[real_length];
    for (int i = 0; i < real_length; i++)
        display_answer[i] = answer[real_length-1-i];
    for (int i = 0; i < real_length; i++)
        cout << display_answer[i];
    return 0;
}
