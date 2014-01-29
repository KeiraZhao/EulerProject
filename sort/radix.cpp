/*
 * radix.cpp
 * Copyright (C) 2014-01-27 
 * Author:      keira 
 * Email:       %MAIL%
 * Funtion:     
 */

#include <iostream>

const int MAXN = 10000;

void radix_sort(int* array, int n, int base=10) {
    int max_element = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max_element) {
            max_element = array[i];
        }
    }
    int exp = 1; 
    int* bucket = new int[base];
    int* array_buffer = new int[n];
    while (max_element / exp) {
        // Clean bucket for current grouping
        for (int i = 0; i < base; i++) {
            bucket[i] = 0;
        }
        // Grouping elements in array by current digit
        for (int i = 0; i < n; i++) {
            bucket[(array[i] / exp) % base]++;
        }
        // Computing positions for each element
        for (int i = 1; i < base; i++) {
            bucket[i] += bucket[i-1];
        }
        // Re-arranging, stable version
        for (int i = n-1; i >= 0; i--) {
            array_buffer[--bucket[(array[i] / exp) % base]] = array[i];
        }
        for (int i = 0; i < n; i++) {
            array[i] = array_buffer[i];
        }
        exp *= base;
    }
    delete bucket;
    delete array_buffer;
}


int main(int argc, char** argv) {
    int n;
    std::cout << "Please enter the number of integers to be sorted: " << std::endl;
    std::cin >> n;
    int* array = new int[n];
    std::cout << "Please enter " << n << " integers: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    radix_sort(array, n);
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
    return 0;
}
