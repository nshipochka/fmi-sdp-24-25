#include "helper_functions.h"
#include <stack>

using std::stack;

// Да направим опашка, използвайки стекове
template <typename T>
class Queue {
public:
	void push(const T& element);
	T pop();

	// Методи, които ни трябват, за да си ползваме print от helper_functions.h
	const T& front() const;
	bool empty() const;
private:
	stack<T> queue_stack, helper_stack;
};

template<typename T>
void Queue<T>::push(const T& element) {
	while (!queue_stack.empty()) {
		helper_stack.push(queue_stack.top());
		queue_stack.pop();
	}

	queue_stack.push(element);

	while (!helper_stack.empty()) {
		queue_stack.push(helper_stack.top());
		helper_stack.pop();
	}
}

template<typename T>
T Queue<T>::pop() {
	// Няма нужда да проверяваме дали е празен и да хвърляме изкл., 
	// ако е празен, стекът ще си хвърли изключението
	T element = queue_stack.top();
	queue_stack.pop();
	return element;
}

template<typename T>
const T& Queue<T>::front() const {
	return queue_stack.top();
}

template<typename T>
bool Queue<T>::empty() const {
	return queue_stack.empty();
}

int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	print(q);

	return 0;
}
