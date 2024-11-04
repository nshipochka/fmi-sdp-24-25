#pragma once
#include "Queue.h"
#include <stdexcept>
#include <cassert>

template <typename T>
struct Node {
	T data;
	Node* next;
	
	Node(const T& data, Node<T>* next = nullptr)
		: data(data)
		, next(next)
	{}
};


template <typename T>
class LinkedQueue : public Queue<T> {
public:
	LinkedQueue()
		: begin(nullptr)
		, end(nullptr)
	{}

	LinkedQueue(const LinkedQueue<T>& other);
	LinkedQueue<T>& operator=(const LinkedQueue<T>& other);
	~LinkedQueue();

	bool full() const override;
	bool empty() const override;

	void enqueue(const T& element) override;
	T dequeue() override;

	const T& front() const override;
	T& front() override;

private:
	void clear();
	void copy(const Node<T>* start);
private:
	Node<T>* begin;
	Node<T>* end;
};

#include "LinkedQueue.inl"


