#pragma once
#include <iostream>
#include <vector>

using std::vector;

void selection_sort(vector<int>& arr) {
    size_t iterations = 0;
    size_t size = arr.size();

    for (int i = 0; i < size - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < size; ++j) {
            iterations++;

            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }

        // If a new minimum is found,
        // swap it with the element at index i
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }

    std::cout << "Number of iterations: " << iterations << std::endl;
}
