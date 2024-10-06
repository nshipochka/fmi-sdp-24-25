#pragma once
#include <iostream>
#include <vector>

using std::vector;

void bubble_sort(vector<int>& arr) {
    bool swapped;
    size_t iterations = 0;
    size_t size = arr.size();

    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        // Гледаме в несортираната част на масива
        for (int j = 0; j < size - i - 1; j++) {
            iterations++;

            // Ако текущият е по-голям от съседа си, сменяме ги
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Ако не сме сменяли елементи, значи масивът е сортиран
        if (!swapped)
            break;
    }

    std::cout << "Number of iterations: " << iterations << std::endl;
}
