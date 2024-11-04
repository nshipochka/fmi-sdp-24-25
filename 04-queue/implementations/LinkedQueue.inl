#include "LinkedQueue.h"
template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
	: begin(nullptr)
{
	try {
		copy(other.begin);
	}
	catch (std::exception& e) {
		clear();
		throw e;
	}
}

template<typename T>
inline LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other) {
	if (this != &other) {
		clear();
		copy(other.begin);
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue() {
	clear();
}

template<typename T>
inline bool LinkedQueue<T>::full() const {
	return false; // Както в автобуса - винаги има място за още един
}

template<typename T>
inline bool LinkedQueue<T>::empty() const {
	return begin == nullptr;
}

template<typename T>
inline void LinkedQueue<T>::enqueue(const T& element) {
	Node<T>* n = new Node<T>(element);

	if (empty()) 
		begin = n;
	else 
		end->next = n;

	end = n; // Ако не е имало елементи, end става равно на begin, ако е имало - на end->next
}

template<typename T>
inline T LinkedQueue<T>::dequeue() {
	// Няма да правим проверка дали е празна опашката,
	// защото взимаме първия елемент с front(),
	// който така или иначе ще хвърли грешката
	T result = front();

	Node<T>* temp = begin;
	begin = begin->next;

	delete temp;
	return result;
}

template<typename T>
inline const T& LinkedQueue<T>::front() const {
	if (empty())
		throw std::underflow_error("Stack is empty");

	return begin->data;
}

template<typename T>
inline T& LinkedQueue<T>::front() {
	if (empty())
		throw std::underflow_error("Stack is empty");

	return begin->data;
}

template<typename T>
inline void LinkedQueue<T>::clear() {
	while (!empty()) {
		Node<T>* temp = begin;
		begin = begin->next;
		delete temp;
	}
}

template<typename T>
inline void LinkedQueue<T>::copy(const Node<T>* start) {
	assert(begin == nullptr && empty());
	while (start) {
		enqueue(start->data);
		start = start->next;
	}
}













