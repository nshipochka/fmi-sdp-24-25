#include <iostream>
#include <queue>
#include <stack>
#include "helper_functions.h"

using std::queue;
using std::stack;
/*
Дадено е цяло число k и опашка от цели числа.
Задачата е да се обърне редът на първите k елемента от опашката,
оставяйки останалите елементи в същия относителен ред.
*/

template <typename T>
void flip_first_k(queue<T>& q, int k) {
	// Вземаме първите k елемента и ги добавяме в стек
	stack<T> s;
	for (int i = 0; i < k; ++i) {
		s.push(q.front());
		q.pop();
	}

	// Връщаме ги в опашката
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	// Преместваме останалите size - k в задната част на опашката
	int size = q.size() - k;
	for (int i = 0; i < size; ++i) {
		q.push(q.front());
		q.pop();
	}
}

int main() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	flip_first_k(q, 3);
	print(q);

	return 0;
}