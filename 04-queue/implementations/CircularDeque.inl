#include "CircularDeque.h"

template <typename T>
CircularDeque<T>::CircularDeque(size_t capacity)
    : data(new T[capacity + 1]), capacity(capacity + 1), front_index(0), back_index(0) {}
    // We set capacity + 1 and keep an empty spot at the end to differentiate between 
    // full: (tail + 1) % capacity == head
    // and empty: head == tail

template <typename T>
CircularDeque<T>::~CircularDeque() {
    delete[] data;
}

template <typename T>
void CircularDeque<T>::push_front(const T& element) {
    if (full()) {
        throw std::overflow_error("Deque is full");
    }
    front_index = (front_index - 1 + capacity) % capacity; // Move front_index backwards
    data[front_index] = element;
}

template <typename T>
void CircularDeque<T>::push_back(const T& element) {
    if (full()) {
        throw std::overflow_error("Deque is full");
    }
    data[back_index] = element;
    back_index = (back_index + 1) % capacity; // Move back_index forwards
}

template <typename T>
T CircularDeque<T>::pop_front() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    T element = data[front_index];
    front_index = (front_index + 1) % capacity; // Move front_index forwards
    return element;
}

template <typename T>
T CircularDeque<T>::pop_back() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    back_index = (back_index - 1 + capacity) % capacity; // Move back_index backwards
    return data[back_index];
}

template <typename T>
const T& CircularDeque<T>::front() const {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    return data[front_index];
}

template <typename T>
T& CircularDeque<T>::front() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    return data[front_index];
}

template <typename T>
const T& CircularDeque<T>::back() const {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    return data[(back_index - 1 + capacity) % capacity];
}

template <typename T>
T& CircularDeque<T>::back() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    return data[(back_index - 1 + capacity) % capacity];
}

template <typename T>
bool CircularDeque<T>::empty() const {
    return front_index == back_index;
}

template <typename T>
bool CircularDeque<T>::full() const {
    return (back_index + 1) % capacity == front_index;
}
