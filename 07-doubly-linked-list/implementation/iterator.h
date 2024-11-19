#pragma once
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedList<T>::iterator {
	iterator(node<T>* ptr);

	DoublyLinkedList<T>::iterator& operator++(); //++i
	DoublyLinkedList<T>::iterator& operator++(int);	//i++

	DoublyLinkedList<T>::iterator& operator--(); //--i
	DoublyLinkedList<T>::iterator& operator--(int); //i--

	bool operator==(const iterator& other);
	bool operator!=(const iterator& other);

	T& operator*();
private:
	friend iterator DoublyLinkedList<T>::begin();
	friend iterator DoublyLinkedList<T>::end() const;

	node<T>* ptr;
};

template <typename T>
inline DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator++() {
	ptr = ptr->next;
	return *this;
}

template <typename T>
inline DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator++(int) {
	auto copy = *this;
	ptr = ptr->next;
	return copy;
}

template <typename T>
inline DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator--() {
	ptr = ptr->prev;
	return *this;
}

template <typename T>
inline DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator--(int) {
	auto copy = *this;
	ptr = ptr->prev;
	return *this;
}

template <typename T>
inline bool DoublyLinkedList<T>::iterator::operator==(const iterator& other) {
	return ptr == other.ptr;
}

template <typename T>
inline bool DoublyLinkedList<T>::iterator::operator!=(const iterator& other) {
	return !operator==(other);
}

template <typename T>
inline T& DoublyLinkedList<T>::iterator::operator*() {
	return ptr->data;
}

template<typename T>
inline DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
	return iterator(head);
}

template<typename T>
inline DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() const {
	return iterator(nullptr);
}







