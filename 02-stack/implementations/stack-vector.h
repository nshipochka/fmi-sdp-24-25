#include <vector>

template <typename T>
class vector_stack {
	bool is_empty() const;
	bool push(const T& x);
	bool pop();

	T& top();
	const T& top() const;

private:
	std::vector<T> data;
};

template <typename T>
bool vector_stack<T>::is_empty() const {
	return data.empty(); // връща дали има елементи в масива
}

template <typename T>
bool vector_stack<T>::push(const T& x) {
	return data.push_back(x); // добавя елемент на последното място в масива
}

template <typename T>
bool vector_stack<T>::pop() {
	return data.pop_back(); // премахва елемента на последното място в масива
}

template <typename T>
T& vector_stack<T>::top(){
	return data.back(); // връща елемента на последното място в масива, като може да се променя
}

template <typename T>
const T& vector_stack<T>::top() const {
	return data.back(); // връща елемента на последното място в масива, като стойността му е read-only
}