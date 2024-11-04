#pragma once
#include "Queue.h"
#include <stdexcept>

template <typename T>
class CircularQueue : public Queue<T> {
public:
	CircularQueue(size_t size = 16)
		: data(new T[size + 1])
		, begin(0)
		, end(0)
		, size(size + 1) {}

	CircularQueue(const CircularQueue<T>& other);
	CircularQueue<T>& operator=(const CircularQueue<T>& other);
	~CircularQueue() { delete[] data; }

	bool full() const override;
	bool empty() const override;

	void enqueue(const T& element) override;
	T dequeue() override;

	const T& front() const override;
	T& front() override;

	size_t count() const {
		return (end + size - begin) % size;
	}

	size_t get_size() const {
		return size;
	}
private:
	T* data;
	size_t begin, end;
	
	const size_t size;
};

#include "CircularQueue.inl"