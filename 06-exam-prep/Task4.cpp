#include "utilities.h"

/*
	Даден е списък с `n` елемента.

	Да се дефинира функция `shuffle()`, която получава адреса на първия елемент на списъка. 

	Функцията да пренарежда възлите на списъка така, че *елементите от втората половина на 
	списъка да се преместят в началото на списъка, но в обратен ред* 

	(при списъци с нечетен брой елементи считаме средния елемент за принадлежащ 
	към втората половина на списъка).
*/

template <typename T>
void reorder(node<T>*& list) {
	node<T>* middle = get_middle_node(list);
	split_before(list, middle);

	node<T>* curr = middle;
	while (curr->next)
		curr = curr->next;

	curr->next = list;
	list = middle;
}

int main() {
	node<int>* list = create_list({ 1,2,3,4,5 });
	reorder(list);
	print(list);

	return 0;
}