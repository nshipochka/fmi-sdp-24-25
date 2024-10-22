#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct Interval {
	int start, end;
	
	friend bool operator<(const Interval& lhs, const Interval& rhs);
};

bool operator<(const Interval& lhs, const Interval& rhs) {
	return lhs.start < rhs.start;
}

void print_interval_stack(stack<Interval> s) {
	while (!s.empty()) {
		std::cout << s.top().start << ", " << s.top().end << std::endl;
		s.pop();
	}
}

// Като искаме вътре да се сортира и да не се отразява навън,
// няма да е const vector<>& и vector<>& аргумента
void merge_intervals(vector<Interval> intervals) { 
	std::sort(intervals.begin(), intervals.end());
	stack<Interval> s;

	for (const Interval& i : intervals) {
		// да добавяме първия след проверка дали е празен стека е по-уместно
		if (s.empty() || i.start > s.top().end) {
			s.push(i);
		}

		if (i.end > s.top().end) {
			s.top().end = i.end;
		}
	}

	print_interval_stack(s);
}

int main() {
	vector<Interval> intervals = {
		{ 1, 5 },
		{ 2, 3 },
		{ 4, 6 },
		{ 7, 8 },
		{ 8, 10 },
		{ 12, 15 }
	};

	merge_intervals(intervals);
}
