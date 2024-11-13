#include "utilities.h"

void reorder_less_than(node<int>* head, int x) {
	node<int> dummy(0, head);
	node<int>* curr = &dummy;

	node<int> dummy_l;
	node<int>* larger = &dummy_l;

	while (curr && curr->next) {
		if (curr->next->data >= x) {
			larger->next = curr->next;
			curr->next = curr->next->next;
			larger = larger->next;
		}
		else
			curr = curr->next;
	}

	if (dummy.next == nullptr)
		dummy.next = dummy_l.next;
	
	else
		curr->next = dummy_l.next;

	head = dummy.next;
}


int main() {
	node<int>* list = create_list({ 1,3,6,2,2,5 });
	reorder_less_than(list, 3);
	print(list);

	return 0;
}