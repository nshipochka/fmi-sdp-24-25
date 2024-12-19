#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Задача 6
bool are_isomorphic(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) 
        return false; 

    unordered_map<char, char> map1, map2;  
    // Речници за съхранение на съответствията между символи

    for (int i = 0; i < str1.length(); ++i) {
        char c1 = str1[i];
        char c2 = str2[i];

        // Проверка за вече съществуващи съответствия
        if (map1.find(c1) != map1.end() && map1[c1] != c2)
            return false;

        if (map2.find(c2) != map2.end() && map2[c2] != c1)
            return false;

        map1[c1] = c2;  // Записваме съответствието за първия низ
        map2[c2] = c1;  // Записваме съответствието за втория низ
    }

    return true;
}

int main() {

    // Задача 1
    std::cout << "Task 1\n";
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    unordered_map<string, int> frequency;

    for (const auto& word : words)
        frequency[word]++;

    for (const auto& [word, count] : frequency) // C++ 17
        std::cout << word << ": " << count << std::endl;


    // Задача 2
    std::cout << "Task 2\n";

    vector<pair<string, string>> items = {{"apple", "fruit"}, {"carrot", "vegetable"}, 
                                          {"banana", "fruit"}, {"broccoli", "vegetable"}};
    unordered_map<string, vector<string>> groups;

    for (const auto& [item, category] : items)
        groups[category].push_back(item);

    for (const auto& [category, items] : groups) {
        std::cout << category << ": ";
        for (const auto& item : items)
            std::cout << item << " ";
        std::cout << std::endl;
    }

    // Задача 3
    std::cout << "Task 3\n";
    string text = "hello world";
    unordered_map<char, char> rules = {{'h', 'H'}, {'e', '3'}, {'o', '0'}};

    for (char& c : text) 
        if (rules.find(c) != rules.end())
            c = rules[c];   

    std::cout << text << std::endl;

    // Задача 4
    std::cout << "Task 4\n";
    vector<int> nums = {8, 7, 2, 5, 3, 1};
    int sum = 10;  

    unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = sum - nums[i];  // Оставащото, което трябва да се намери

        if (num_map.find(complement) != num_map.end())
            std::cout << "(" << num_map[complement] << ", " << i << ")" << std::endl;

        num_map[nums[i]] = i;  // Добавяме текущото число в речника с неговия индекс
    }

    // Задача 5
    std::cout << "Task 5\n";
    vector<pair<int, int>> pairs = {{3, 4}, {1, 2}, {5, 2}, {7, 10}, {4, 3}, {2, 5}};
    unordered_map<int, int> pair_map;  // Речник за съхранение на срещаните първи елементи на двойките

    for (const auto& p : pairs) {
        int first = p.first;
        int second = p.second;

        if (pair_map.find(second) != pair_map.end() && pair_map[second] == first) {
            std::cout << "(" << second << ", " << first << ") and (" << first << ", " << second << ")" << std::endl;
        } else {
            pair_map[first] = second;  // Добавяме първия елемент на двойката в речника
        }
    }

    // Задача 6
    std::cout << "Task 6\n";
    string str1 = "ACAB";
    string str2 = "XCXY";

    std::cout << are_isomorphic(str1, str2) ? "Yes" : "No";
    std::cout << std::endl;
    
    return 0;
}
