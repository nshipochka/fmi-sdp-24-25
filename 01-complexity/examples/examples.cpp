#include "./sort/bubble_sort.h"
#include "./sort/insertion_sort.h"
#include "./sort/selection_sort.h"
#include "./sort/merge_sort.h"
#include "./sort/quick_sort.h"

#include "./search/linear_search.h"
#include "./search/binary_search.h"

#include <iostream>
#include <vector>

using std::vector;

int main() {

    vector<int> short_arr = {1, 5, -1, 2, 10, 11, 14, 15};
    vector<int> long_arr = { 1, 2, 3, 4, 1, -1, 4, -4, 10, 11, 3, 5, -23, 7, -10, 15, 14, 16, 2, 10, -15, 3, 33, 154, -211, 1, 1, -13, 23, 29, 5 };

    size_t s_size = short_arr.size();
    std::cout << "n: " << s_size << ", log(n): " << std::log(s_size) << ", n * log(n): " << s_size * std::log(s_size) << ", n^2: " << s_size * s_size << std::endl;

    size_t l_size = long_arr.size();
    std::cout << "n: " << l_size << ", log(n): " << std::log(l_size) << ", n * log(n): " << l_size * std::log(l_size) << ", n^2: " << l_size * l_size << std::endl;

    // Sorting
    
    // Bubble Sort:
    /*std::cout << "bubble sort: \n";
    bubble_sort(short_arr);
    bubble_sort(long_arr);*/

    // Insertion Sort
    /*std::cout << "insertion sort: \n";
    insertion_sort(short_arr);
    insertion_sort(long_arr);*/
    
    // Selection Sort
    /*std::cout << "selection sort\n";
    selection_sort(short_arr);
    selection_sort(long_arr);*/

    // Merge Sort
    std::cout << "merge sort\n";
    merge_sort(short_arr);
    merge_sort(long_arr);


    // Linear Search
    std::cout << "\nlinear search\n";
    linear_search(short_arr, 11);
    linear_search(short_arr, 1000);

    std::cout << "\n";

    linear_search(long_arr, 11);
    linear_search(long_arr, 1000);


    // Binary Search
    std::cout << "\nbinary search\n";
    binary_search(short_arr, 0, s_size - 1, 11);
    binary_search(short_arr, 0, s_size - 1, 1000);

    std::cout << "\n";

    binary_search(long_arr, 0, l_size - 1, 11);
    binary_search(long_arr, 0, l_size - 1, 1000);


	return 0;
}