#include <iostream>
#include <stack>

using std::stack;

template <typename T>
void print_stack(stack<T> s) {
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
}

void fill_stack(stack<int>& s) {
	for (size_t i = 0; i < 10; i++)
		s.push(rand() % 100);
}

template <typename T>
void sort_stack(stack<T>& s) {
	stack<T> temp_stack;
	
	while (!s.empty()) {
		T curr_element = s.top();
		s.pop();
		
		while (!temp_stack.empty() && temp_stack.top() < curr_element) {
			s.push(temp_stack.top());
			temp_stack.pop();
		}

		temp_stack.push(curr_element);
	}

	std::swap(s, temp_stack);
}

int main() {
	stack<int> s;
	fill_stack(s);
	print_stack(s);
	std::cout << std::endl;
	
	sort_stack(s);
	print_stack(s);
}