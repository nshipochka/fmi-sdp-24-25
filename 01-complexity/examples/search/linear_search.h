#pragma once
#include <iostream>

void linear_search(vector<int>& arr, int x) {
    size_t iterations = 0;
    size_t size = arr.size();

    for (size_t i = 0; i < size; ++i) {
        iterations++;

        // Проверяваме дали текущият елемент е x
        if (arr[i] == x) {
            std::cout << "Element is at index: " << i << std::endl;
            std::cout << "Number of iterations: " << iterations << std::endl;
            return;
        }
    }

    std::cout << "No such element." << std::endl;
    std::cout << "Number of iterations: " << iterations << std::endl;
}