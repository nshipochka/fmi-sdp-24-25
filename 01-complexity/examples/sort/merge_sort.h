#pragma once
#include <iostream>
#include <vector>

using std::vector;

// Слива два подмасива на arr[].
// Първият подмасив е arr[left..mid]
// Вторият подмасив е arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right, size_t& iterations) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Създаваме два временни вектора, които да
    vector<int> L(n1), R(n2);

    // Разделяме данните в двата вектора L[] и R[]
    for (int i = 0; i < n1; i++) {
        iterations++;
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        iterations++;
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    // Сливаме временните вектори обратно в arr[left..right] според големината на елементите
    while (i < n1 && j < n2) {
        iterations++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копираме ако има останало от L[], 
    while (i < n1) {
        iterations++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копираме ако има останало от R[], 
    while (j < n2) {
        iterations++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int left, int right, size_t& iterations) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, iterations);
    merge_sort(arr, mid + 1, right, iterations);
    merge(arr, left, mid, right, iterations);
}

void merge_sort(vector<int>& arr) {
    size_t iterations = 0;
    merge_sort(arr, 0, arr.size() - 1, iterations);
    std::cout << "Number of iterations: " << iterations << std::endl;
}