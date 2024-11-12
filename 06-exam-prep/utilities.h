#pragma once
#include <iostream>

template <typename T>
struct node {
	T data;
	node* next;

	node(const T& data = T(), node* next = nullptr)
		: data(data), next(next) {}
};

template <typename T>
node<T>* create_list(const std::initializer_list<T>& values) {
	node<T> dummy;
	node<T>* curr = &dummy;

	for (const T& val : values) {
		curr->next = new node<T>(val);
		curr = curr->next;
	}

	return dummy.next;
}

template <typename T>
void delete_list(node<T>*& list) {
	node<T>* curr = list;

	while (curr) {
		node<T>* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}

	list = nullptr;
}

template <typename T>
void print(node<T>* list) {
	while (list) {
		std::cout << list->data << " ";
		list = list->next;
	}
	std::cout << std::endl;
}

template <typename T>
node<T>* get_middle_node(node<T>* head) {
	node<T>* slow = head;
	node<T>* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

template <typename T>
void reverse_list(node<T>*& head) {
	node<T>* curr = head;
	node<T>* prev = nullptr;
	node<T>* next = nullptr;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

template <typename T>
void split_before(node<T>* list, node<T>* const position) {
	if (!list) return;

	while (list && list->next) {
		if (list->next == position) {
			list->next = nullptr;
			return;
		}

		list = list->next;
	}
}