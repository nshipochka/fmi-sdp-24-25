#include "CircularQueue.h"
template <typename T>
inline CircularQueue<T>::CircularQueue(const CircularQueue<T>& other)
	: data(new T[other.size])
	, begin(0)
	, end(0)
	, size(other.size)
{
	for(size_t i = other.begin; i != other.end; i = (i + 1) % size)
		enqueue(other.data[i]); 
		// Възползваме се от интерфейса на опашката
}

template <typename T>
inline CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue<T>& other) {
	if(this != &other) {
		begin = end = 0;
		for(size_t i = other.begin; i != other.end; i = (i + 1) % size)
			enqueue(other.data[i]);
		// Ако размерът на other е по-голям, 
		// като препълним текущата опашка, enqueue ще хвърли грешка
	}
	return *this;
}

template <typename T>
inline bool CircularQueue<T>::full() const {
	return (end + 1) % size == begin;
	// end сочи къде ще се добавя следващ елемент
}

template <typename T>
inline bool CircularQueue<T>::empty() const {
	return begin == end;
}

template <typename T>
inline void CircularQueue<T>::enqueue(const T& element) {
	if(full()) 
		throw std::overflow_error("Queue is full");

	data[end] = element;
	end = (end + 1) % size;
	// Ако дадем само end + 1, това може да е извън масива 
	// и да трябва да започнем от началото на кръгчето.
	// Спестяваме си проверка като просто взимаме остатъка по размера.
}

template <typename T>
inline T CircularQueue<T>::dequeue() {
	if(empty()) 
		throw std::underflow_error("Queue is empty");

	const T& result = data[begin];
	begin = (begin + 1) % size; 
	// Същото като с end + 1
	return result;
}

template <typename T>
inline const T& CircularQueue<T>::front() const {
	if(empty()) 
		throw std::underflow_error("Queue is empty");
	
	return data[begin];
}

template<typename T>
inline T& CircularQueue<T>::front() {
	if (empty()) 
		throw std::underflow_error("Queue is empty");
	
	return data[begin];
}
