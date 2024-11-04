#pragma once
#include "helper_functions.h"
#include <queue>
using std::queue;

// Да направим стек, използвайки опашки
template <typename T>
class Stack {
public:
    void push(const T& element);
    T pop();
    
    // Методи, които ни трябват да си ползваме print от helper_functions
    const T& front() const;
    bool empty() const;

private:
    queue<T> stack_queue, helper_queue;
};

template<typename T>
void Stack<T>::push(const T& element) {
    helper_queue.push(element);

    while (!stack_queue.empty()) {
        helper_queue.push(stack_queue.front());
        stack_queue.pop();
    }

    // Разменяме им съдържанието, т.е. връщаме данните обратно в stack_queue
    // в реда, в който се очаква да са
    std::swap(helper_queue, stack_queue);
}

template<typename T>
T Stack<T>::pop() {
    T element = stack_queue.front();
    stack_queue.pop();
    return element;
}

template<typename T>
const T& Stack<T>::front() const {
    return stack_queue.front();
}

template<typename T>
bool Stack<T>::empty() const {
    return stack_queue.empty();
}

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    print(s);

    return 0;
}



