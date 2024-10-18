#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

bool is_opening_bracket(char c) {
	return c == '(' || c == '[' || c == '{';
}

bool is_closing_bracket(char c) {
	return c == ')' || c == ']' || c == '}';
}

char get_corresponding_bracket(char closing) {
	switch (closing) {
	case ')':
		return '(';

	case ']':
		return '[';

	case '}':
		return '{';

	default:
		return 0;
	}
}

bool is_correctly_bracketed(const string& s) {
	stack<char> brackets;

	for (char c : s) {
		if (is_opening_bracket(c))
			brackets.push(c);

		else if (is_closing_bracket(c)) {
			if (brackets.empty() || get_corresponding_bracket(c) != brackets.top())
				return false;

			else
				brackets.pop();
		}
	}

	return	brackets.empty();
}

int main() {
	string s1 = "(3+6)/{54g(p3[jw ][])}";
	string s2 = "{(526)}[91]}";

	std::cout << std::boolalpha << is_correctly_bracketed(s2);


	return 0;
}