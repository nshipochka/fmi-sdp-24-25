#include <iostream>
#include <string>
#include <sstream>
//#include "bst.h"

using std::string;
using std::stringstream;

struct node {
	int data;
	node* left;
	node* right;

	node(int data = 0, node* left = nullptr, node* right = nullptr)
		: data(data), left(left), right(right) {}
};

int parse_int(stringstream& ss) {
	int num = 0;
	char c;

	while (isdigit(ss.peek())) {
		ss >> c;
		num *= 10;
		num += c - '0';
	}

	return num;
}

node* parse_tree(stringstream& ss) {
	char c;
	
	node* new_tree = nullptr;

	ss >> c; // '('
	if (ss.peek() == ')') {
		while (ss.peek() == ')') {
			ss >> c;
		}
		new_tree = nullptr;
	}
	else {
		int data = parse_int(ss);

		node* left_tree = parse_tree(ss);
		node* right_tree = parse_tree(ss);

		new_tree = new node(data,
			left_tree,
			right_tree);
	}

	return new_tree;
}

void print_in_order(const node* root) {
	if (!root)
		return;

	print_in_order(root->left);
	std::cout << root->data << " ";
	print_in_order(root->right);
}

void print_reverse_in_order(const node* root) {
	if (!root)
		return;

	print_reverse_in_order(root->right);
	std::cout << root->data << " ";
	print_reverse_in_order(root->left);
}

int sum(const node* root) {
	if (!root)
		return 0;

	return root->data + sum(root->left) + sum(root->right);
}

int main() {
	string input = "(10(7(2()())(8()()))(12(11()())(15()())))";
	stringstream ss(input);
	node* tree = parse_tree(ss);

	print_in_order(tree);
	std::cout << std::endl;

	print_reverse_in_order(tree);
	std::cout << std::endl;

	std::cout << sum(tree) << std::endl;

	return 0;
}