#pragma once
#include <fstream>

template <typename T>
class DoublyLinkedList {
private:
	struct node {
		T data;
		node* next;
		node* prev;

		node(T data = T(), node* prev = nullptr, node* next = nullptr)
			: data(data), prev(prev), next(next) {};
	};

public:
	DoublyLinkedList();
	DoublyLinkedList(std::initializer_list<T> list);
	DoublyLinkedList(const DoublyLinkedList<T>& other);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
	~DoublyLinkedList();

	bool is_empty() const;
	size_t get_size() const { return size; };

	void push_front(const T& value);
	void push_back(const T& value);

	void pop_front();
	void pop_back();

	T peek_front() const;
	T peek_back() const;

	class iterator;

	iterator begin();
	iterator end() const;

	friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list);

private:
	void copy(const DoublyLinkedList<T>& other);
	void clear();

private:
	node* head;
	node* tail;
	size_t size;
};

#include "DoublyLinkedList.inl"
#include "iterator.inl"

