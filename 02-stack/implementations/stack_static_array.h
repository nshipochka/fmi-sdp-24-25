#pragma once
#include <stdexcept>

template <typename T>
class static_stack {
public:
	static_stack<T>(const size_t size);
	static_stack<T>(const static_stack<T>& other);
	static_stack<T>& operator=(const static_stack<T>& other);
	~static_stack<T>();

	void push(const T& element);
	T pop();

	T& top();
	const T& top() const;

	bool is_empty() const;
	bool is_full() const;

private:
	T* data;
	const size_t size;
	
	size_t pos;
};

template<typename T>
inline bool static_stack<T>::is_empty() const {
	return pos == 0;
}

template<typename T>
inline bool static_stack<T>::is_full() const {
	return pos == size;
}

template<typename T>
inline void static_stack<T>::push(const T& element) {
	if (is_full()) throw std::overflow_error("Stack is full");
	data[pos++] = element;
}

// Връщаме копие на елемента от тип T, понеже в самия стек вече няма да съществува
template<typename T>
inline T static_stack<T>::pop() {
	if (is_empty()) throw std::underflow_error("Stack is empty");
	return data[--pos];
}

// Може да върнем по референция, понеже елементът съществува в стека
template<typename T>
inline T& static_stack<T>::top() {
	if (is_empty()) throw std::underflow_error("Stack is empty");
	return data[pos - 1];
}

template<typename T>
inline const T& static_stack<T>::top() const {
	if (is_empty()) throw std::underflow_error("Stack is empty");
	return data[pos-1];
}

// Голяма 4-ка
template<typename T>
inline static_stack<T>::static_stack(const size_t size) 
	: data(new T[size])
	, size(size)
	, pos(0)
{}

template<typename T>
inline static_stack<T>::static_stack(const static_stack<T>& other)
	: data(new T[other.size])
	, size(other.size)
	, pos(0)
{
	while (pos < other.pos)
		push(other.data[pos]);
}

template<typename T>
inline static_stack<T>& static_stack<T>::operator=(const static_stack<T>& other) {
	if (this != &other) {
		if (other.size > size) throw std::overflow_error("Stack will overflow");

		pos = 0;
		while (pos < other.pos)
			push(other.data[pos]);
	}

	return *this;
}

template<typename T>
inline static_stack<T>::~static_stack() {
	delete[] data;
}
