#include <stack>
using std::stack;

// Взима един по един елементите от dest и ги слага в src 
template <typename T>
void take_elements(stack<T>& dest, stack<T>& src) {
	while (!src.empty()) {
		dest.push(src.top());
		src.pop();
	}
}

template <typename T>
void reverse_stack(stack<T>& s) {
	stack<T> reversed;
	take_elements(reversed, s);
	std::swap(s, reversed);
}

// Защо работим с копия? 
// Защото, ако подадем аргументите като stack<T>&, промените ще се отразят извън функцията, а const stack<T>& няма да ни позволи да ползваме метода pop().
template <typename T>
stack<T> merge_stacks(stack<T> first, stack<T> second) {
	stack<T> merged;
	
	reverse(first);
	reverse(second);

	take_elements(merged, first);
	take_elements(merged, second);
}