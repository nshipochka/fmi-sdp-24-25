#include "utilities.h"
/*
	Да се напише функция, която проверява дали свързан списък е палиндром.
*/

bool is_palindrome(node<int>* left) {
	node<int>* right = get_middle_node(left);
	reverse_list(right);

	while (right) {
		if (right->data != left->data)
			return false;

		right = right->next;
		left = left->next;
	}

	return true;
}


int main() {
	node<int>* list = create_list({ 1,2,2,1 });
	std::cout << is_palindrome(list);

	delete_list(list);

	return 0;
}
