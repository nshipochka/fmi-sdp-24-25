#ifndef _LINKED_LIST_ITERATOR_H_
#define _LINKED_LIST_ITERATOR_H_

#include "LinkedList.h"

template <typename T>
class LinkedList<T>::iterator {
public:
    bool valid() const { return ptr; }
    operator bool() const { return ptr; }

    T& operator*() { return ptr->data; }
    T* operator->() { return &ptr->data; }
    const T& operator*() const { return ptr->data; }
    const T* operator->() const { return &ptr->data; }

    iterator& operator++() {
        ptr = ptr->next;
        return *this;
    }

    iterator operator++(int) {
        iterator res = *this;
        ++*this;
        return res;
    }

    bool operator == (const iterator& rhs) const {
        return ptr == rhs.ptr;
    }

    bool operator != (const iterator& rhs) const {
        return !(*this == rhs);
    }

private:
    friend iterator LinkedList<T>::begin();
    friend iterator LinkedList<T>::end() const;

    LinkedList<T>::node* ptr;
    iterator(LinkedList<T>::node* ptr)
        : ptr(ptr) {}
};

template<class T>
inline typename LinkedList<T>::iterator LinkedList<T>::begin() {
    return iterator(head);
}

template<class T>
inline typename LinkedList<T>::iterator LinkedList<T>::end() const {
    return iterator(nullptr);
}

#endif