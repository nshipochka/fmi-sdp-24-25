#include <iostream>
#include "utilities.h"
/*
	Напишете функция, която пренарежда свързан списък по зададен начин в линейно време.

	Представяме списъка като:
	`L0 → L1 → … → Ln - 1 → Ln`

	Пренареждаме елементите му по следния начин:
	`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`
*/

template <typename T>
void reorder_list(node<T>* left) {
	node<T>* right = get_middle_node(left);
	
	// Искаме да разделим списъка на 2 части
	node<T>* mid = right;
	right = right->next;
	mid->next = nullptr;
	
	reverse_list(right);
	// Сега сочи Ln

	while (right) {
		node<T>* left_next = left->next;
		node<T>* right_next = right->next;

		left->next = right;
		right->next = left_next;

		left = left_next;
		right = right_next;
	}
}

int main() {
	node<int>* head = create_list({1,2,3,4,5});
	print(head);

	reorder_list(head);
	print(head);

	delete_list(head);

	return 0;
}