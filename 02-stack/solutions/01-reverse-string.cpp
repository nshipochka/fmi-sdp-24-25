#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using std::string;
using std::stack;
using std::stringstream;

void reverse(string& s) {
	stringstream stream(s);
	string word;
	stack<string> words;

	while (stream >> word)
		words.push(word);

	s.clear();
	while (!words.empty()) {
		s += words.top() + ' ';
		words.pop();
	}
}

int main() {
	string text = "Hello world it's me Nadi";
	reverse(text);
	std::cout << text;

	return 0;
}