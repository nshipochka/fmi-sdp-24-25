#pragma once
template <typename T>
class Queue {
public:
	virtual bool is_full() const = 0;
	virtual bool is_empty() const = 0;

	virtual void enqueue(const T& element) = 0;
	virtual T dequeue() = 0;
	
	virtual const T& front() const = 0;
	T& front() = 0;

	virtual ~Queue() {};
};