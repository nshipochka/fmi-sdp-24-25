#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <initializer_list>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
	struct node {
		T data;
		node* next;

		node(const T& data = T(), node* next = nullptr)
			: data(data), next(next) {};
	};

public:
	LinkedList() 
		: head(nullptr), tail(nullptr), sz(0) {};

	// От C++11
	LinkedList(const std::initializer_list<T>& values);
	LinkedList(const LinkedList<T>& other);
	LinkedList<T>& operator=(const LinkedList<T>& other);
	~LinkedList();

	// Итератор
	class iterator;

	iterator begin();
	iterator end() const;

	// Четене на елемент
	const T& front() const;
	const T& back() const;
	const T& at(size_t pos) const;

	// Информативни методи
	bool empty() const { return sz == 0; };
	size_t size() const { return sz; };

	// Добавяне на елементи
	void push_front(const T& val);
	void push_back(const T& val);
	void push_at_pos(size_t pos, const T& val);

	// Премахване на елементи
	T pop_front();
	T pop_back();
	T pop_at_pos(size_t pos);

	// Алгоритми
	void reverse();
	void to_set();

	void filter(bool (* f)(const T&));
	void map(void (* f)(T&));

private:
	void copy(const LinkedList<T>& other);
	void free();

	node* head;
	node* tail;
	size_t sz;
};

#include "LinkedList.inl"

#endif




