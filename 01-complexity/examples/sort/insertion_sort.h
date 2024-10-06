#pragma once
#include <iostream>
#include <vector>

using std::vector;

void insertion_sort(vector<int>& arr) {
    size_t n = arr.size();
    size_t iterations = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Докато не стигнем елемент по-голям от arr[i] в arr[0..i-1], 
        шифтваме елементите надясно, за да освободим място за стойността на arr[i]  */
        while (j >= 0 && arr[j] > key) {
            iterations++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Слагаме стойността на arr[i] на свободната позиция 
        arr[j + 1] = key;
    }

    std::cout << "Number of iterations: " << iterations << std::endl;
}