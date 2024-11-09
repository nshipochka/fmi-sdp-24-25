#pragma once
#include <iostream>
#include <string>

#include "Author.h"

using std::string;

class Library {
	struct node {
		Author data;
		node* next;

		node(Author data = Author(), node* next = nullptr)
			: data(data), next(next) {};
	};

public:
	Library(const char* filename);
	~Library() { free(); }

	void filter(bool (*predicate) (const Author&));

private:
	// Вмъква to_insert на съответното място в списъка по азбучен ред
	void insert_node(node* to_insert);
	void deserialize();
	void free();

private:
	string filename;
	node* head;
};

Library::Library(const char* filename)
	: filename(filename)
	, head(nullptr)
{
	try {
		deserialize();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
		free();
	}
}

void Library::filter(bool (*predicate) (const Author&)) {
	node* curr = head;
	std::string filename = "authors_not.txt";

	std::ofstream out(filename);
	if (!out)
		throw std::exception("Stream error: can't write to file");

	while (curr) {
		if (!predicate(curr->data))
			out << curr->data;
		curr = curr->next;
	}
}

void Library::insert_node(node* to_insert) {
	if (!head)
		head = to_insert;
	else {
		node* curr = head;
		// Местим, докато не стигнем мястото за добавяне или края
		while (curr->next && to_insert->data > curr->data)
			curr = curr->next;

		to_insert->next = curr->next;
		curr->next = to_insert;
	}
}

void Library::deserialize() {
	std::ifstream in(filename, std::ios::binary);

	if (!in)
		throw std::exception("Stream error: Can't read from file");

	while (!in.eof()) {
		node* to_insert = new node;
		to_insert->data.deserialize(in);

		if (!in.eof())
			insert_node(to_insert);
	}
}

void Library::free() {
	node* curr = head;
	while (curr) {
		node* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}
}