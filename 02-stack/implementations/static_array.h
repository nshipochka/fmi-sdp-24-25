#pragma once
#include <stdexcept>

template <typename T>
class static_array {
public:
	static_array<T>(const size_t size);
	static_array<T>(const static_array<T>& other);
	static_array<T>& operator=(const static_array<T>& other);
	~static_array<T>();

	void push_back(const T& element);
	T pop_back();

	T& top();
	const T& top() const;

	bool empty() const;
	bool full() const;

private:
	T* data;
	const size_t size;

	size_t pos;
};

template<typename T>
inline bool static_array<T>::empty() const {
	return pos == 0;
}

template<typename T>
inline bool static_array<T>::full() const {
	return pos == size;
}

template<typename T>
inline void static_array<T>::push_back(const T& element) {
	if (full()) throw std::overflow_error("Stack is full");
	data[pos++] = element;
}

// Връщаме копие на елемента от тип T, понеже в самия стек вече няма да съществува
template<typename T>
inline T static_array<T>::pop_back() {
	if (empty()) throw std::underflow_error("Stack is empty");
	return data[--pos];
}

// Може да върнем по референция, понеже елементът съществува в стека
template<typename T>
inline T& static_array<T>::top() {
	if (is_empty()) throw std::underflow_error("Stack is empty");
	return data[pos - 1];
}

template<typename T>
inline const T& static_array<T>::top() const {
	if (is_empty()) throw std::underflow_error("Stack is empty");
	return data[pos - 1];
}

// Голяма 4-ка
template<typename T>
inline static_array<T>::static_array(const size_t size)
	: data(new T[size])
	, size(size)
	, pos(0)
{}

template<typename T>
inline static_array<T>::static_array(const static_array<T>& other)
	: data(new T[other.size])
	, size(other.size)
	, pos(0)
{
	while (pos < other.pos)
		push_back(other.data[pos]);
}

template<typename T>
inline static_array<T>& static_array<T>::operator=(const static_array<T>& other) {
	if (this != &other) {
		if (other.size > size) throw std::overflow_error("Stack will overflow");

		pos = 0;
		while (pos < other.pos)
			push_back(other.data[pos]);
	}

	return *this;
}

template<typename T>
inline static_array<T>::~static_array() {
	delete[] data;
}
