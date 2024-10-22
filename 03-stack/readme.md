# Linked Stack

При имплементацията на свързан стек, отдолу стои контейнерът свързан списък.

## Linked List (по-нататък по-подробно)
![Linked List](linked-list.png)

### Операции
- Вмъкване на елемент:  
    ```c++
    void push_front(const T& element); // O(1)
    void push_back(const T& element); // O(n);
    void push_at_pos(size_t pos, const T& element); // O(n)
    ```
- Премахване на елемент:    
    ```c++
    void pop_front(); // O(1)
    void pop_end(); // O(n)
    T pop_at_pos(size_t pos); // O(n)
    ```
- Намиране на елемент:
    ```c++
    const T& front() const; // O(1)
    const T& back() const; // O(n)
    cont T& at(size_t pos) const; // O(n)
    ```

При имплементацията на стек чрез този контейнер, ние се възползваме от методите извършващи опреации в началото на списъка и това, че те са със сложност O(1).

### Имплементация

```c++
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data = T(), Node* next = nullptr) : data(data), next(next) {};
;}

template <typename T>
class stack_linked {
public:
    bool empty() const {
        return m_top == nullptr;
    }

    void push(const T& element) {
        m_top = new Node<T>(element, m_top)
    }

    T pop() {
        if (empty())
            throw std::underflow_error("Stack is empty");
        
        Node* detach = m_top;

        m_top = m_top->next;
        T stored_data = detach->data;

        delete detach;
        return stored_data;
    } 

    // Т& top() { ... }

    const T& top() const { 
        if (empty())
            throw std::underflow_error("Stack is empty");

        return top->data;
    }

    // ТРЯБВА да имаме деструктор, понеже заделяме нова памет при всяко добавяне
private:
    Node* m_top;
};
```

# Симулиране на рекурсия
Имаме лабиринт с 0 - път, 1 - стена и искаме да намерим има ли път от началото (0, 0) до края (3, 3).
```
0 1 0 1
0 1 0 0
0 0 0 1
0 1 0 0
```
- [С рекурсия](./solutions/maze_recursion.cpp)
- [Със стек](./solutions/maze_stack.cpp)

## [CMake](../misc/cmake.md)

## [Doctest Tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md)

# Задачи
### 1: Merging Overlapping Intervals
Given a set of intervals, print all non-overlapping intervals after merging the overlapping intervals.

```
Input:  {1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}
Output: Intervals after merging overlapping intervals are {1, 6}, {7, 10}, {12, 15}. 
```
