#pragma once
#include <vector>

template <typename T, typename ContainerType>
class template_stack {
	bool is_empty() const;
	bool push(const T& x);
	bool pop();

	T& top();
	const T& top() const;

private:
	ContainerType<T> data;
};

template <typename T, typename ContainerType>
bool template_stack<T, ContainerType>::is_empty() const {
	return data.empty(); // Изисква се ContainerType да има методи с тези имена
}

template <typename T, typename ContainerType>
bool template_stack<T, ContainerType>::push(const T& x) {
	return data.push_back(x);
}

template <typename T, typename ContainerType>
bool template_stack<T, ContainerType>::pop() {
	return data.pop_back();
}

template <typename T, typename ContainerType>
T& template_stack<T, ContainerType>::top() {
	return data.back();
}

template <typename T, typename ContainerType>
const T& template_stack<T, ContainerType>::top() const {
	return data.back();
}