#pragma once
template <typename T>
class DoublyLinkedList<T>::iterator {
public:
	iterator(node* ptr) : ptr(ptr) {}

	iterator& operator++(); //++i
	iterator& operator++(int);	//i++

	iterator& operator--(); //--i
	iterator& operator--(int); //i--

	bool operator==(const iterator& other) const;
	bool operator!=(const iterator& other) const;

	T& operator*() const;
	
	friend iterator DoublyLinkedList<T>::begin();
	friend iterator DoublyLinkedList<T>::end() const;

private:
	node* ptr;
};

template <typename T>
inline typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator++() {
	ptr = ptr->next;
	return *this;
}

template <typename T>
inline typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator++(int) {
	auto copy = *this;
	ptr = ptr->next;
	return copy;
}

template <typename T>
inline typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator--() {
	ptr = ptr->prev;
	return *this;
}

template <typename T>
inline typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator--(int) {
	auto copy = *this;
	ptr = ptr->prev;
	return *this;
}

template <typename T>
inline bool DoublyLinkedList<T>::iterator::operator==(const iterator& other) const {
	return ptr == other.ptr;
}

template <typename T>
inline bool DoublyLinkedList<T>::iterator::operator!=(const iterator& other) const {
	return !operator==(other);
}

template <typename T>
inline T& DoublyLinkedList<T>::iterator::operator*() const {
	return ptr->data;
}

template<typename T>
inline typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
	return iterator(head);
}

template<typename T>
inline typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() const {
	return iterator(nullptr);
}