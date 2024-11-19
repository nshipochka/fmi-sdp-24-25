#include "DoublyLinkedList.h"
template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() 
	: head(nullptr), tail(nullptr), size(0)
{}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> list)
	: DoublyLinkedList()
{
	for (const T& element : list) {
		push_back(element);
	}
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) 
	: DoublyLinkedList()
{	
	copy(other);
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList() {
	clear();
}

template<typename T>
inline bool DoublyLinkedList<T>::is_empty() const {
	return size == 0;
}

// to test: push in is_empty list

template<typename T>
inline void DoublyLinkedList<T>::push_front(const T& value) {
	node* prev_head = head;
	head = new node(value, nullptr, prev_head);
	size++;
	
	if(prev_head)
		prev_head->prev = head;

	if (!prev_head)
		tail = head;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T& value) {
	node* prev_tail = tail;
	tail = new node(value, prev_tail);
	size++;

	if(prev_tail)
		prev_tail->next = tail;

	if (!prev_tail)
		head = tail;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front() {
	if (is_empty())
		throw std::underflow_error("DLL is is_empty");

	node* to_delete = head;
	
	head = head->next;
	if(head)
		head->prev = nullptr;

	delete to_delete;
	size--;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back() {
	if (is_empty())
		throw std::underflow_error("DLL is is_empty");

	node* to_delete = tail;

	tail = tail->prev;
	if(tail)
		tail->next = nullptr;

	delete to_delete;
	size--;
}

template<typename T>
inline T DoublyLinkedList<T>::peek_front() const {
	if (is_empty())
		throw std::underflow_error("DLL is is_empty");

	return head->data;
}

template<typename T>
inline T DoublyLinkedList<T>::peek_back() const {
	if (is_empty())
		throw std::underflow_error("DLL is is_empty");
	return tail->data;
}

template<typename T>
inline void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& other) {
	node* curr = other.head;
	while (curr) {
		push_back(curr->data);
		curr = curr->next;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::clear() {
	node* curr = head;
	while (curr) {
		node* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list) {
	for (auto element : list) {
		out << element->data << " ";
	}
	return out;
}
