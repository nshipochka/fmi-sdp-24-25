#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <stdexcept>

template <typename T>
class CircularDeque {
public:
    CircularDeque(size_t capacity = 4);
    ~CircularDeque();

    void push_front(const T& element);
    void push_back(const T& element);
    T pop_front();
    T pop_back();

    const T& front() const;
    T& front();
    const T& back() const;
    T& back();

    bool empty() const;
    bool full() const;

    size_t get_size() const {
        return capacity;
    }

private:
    T* data;
    const size_t capacity;
    size_t front_index;
    size_t back_index;
};

#include "CircularDeque.inl" // Include the implementation file

#endif // CIRCULAR_DEQUE_H
