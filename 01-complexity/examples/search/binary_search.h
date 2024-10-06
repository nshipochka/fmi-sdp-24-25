#pragma once
#include <iostream>

void binary_search(vector<int>& arr, int low, int high, int x) {
    int iterations = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        iterations++;

        // Проверяваме следния елемент дали е търсеният
        if (arr[mid] == x) {
            std::cout << "Element is at index: " << mid << std::endl;
            std::cout << "Number of iterations: " << iterations << std::endl;
            return;
        }

        // Ако x е по-голямо от средното, гледаме надясно
        if (arr[mid] < x)
            low = mid + 1;

        // Ако x е по-малко от средното, гледаме наляво
        else
            high = mid - 1;
    }

    std::cout << "No such element." << std::endl;
    std::cout << "Number of iterations: " << iterations << std::endl;
}