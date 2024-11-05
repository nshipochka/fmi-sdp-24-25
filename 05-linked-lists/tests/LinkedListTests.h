#include "../../doctest.h"
#include "../implementations/LinkedList.h"

typedef LinkedList<int> list;

TEST_CASE("Creating empty list") {
	list l;
	CHECK(l.empty());
}

TEST_CASE("Inserting an element makes the list non-empty") {
	list l;
	SUBCASE("Insert in front") {
		l.push_front(1);
		CHECK(!l.empty());
	}

	SUBCASE("Insert at back") {
		l.push_back(1);
		CHECK(!l.empty());
	}
}

TEST_CASE("Pushing elements") {
	list l { 1 }; 

	l.push_front(0);
	l.push_back(4);
	l.push_at_pos(2, 2);
	l.push_at_pos(3, 3);

	// 1 2 3 4 5

	for (size_t i = 0; i < 5; ++i)
		CHECK(i == l.at(i));

	SUBCASE("Pushing at invalid position") {
		CHECK_THROWS(l.push_at_pos(-1, 0));
	}
}

TEST_CASE("Popping elements") {
	list l;

	SUBCASE("Popping from an empty list") {
		CHECK_THROWS(l.pop_at_pos(0));
	}

	SUBCASE("Popping at invalid position") {
		CHECK_THROWS(l.pop_at_pos(1));
	}

	SUBCASE("Popping at valid positions") {
		const size_t test_size = 100;
		for (size_t i = 0; i < test_size; ++i)
			l.push_at_pos(i, i);

		for (size_t i = 0; i < test_size; ++i)
			CHECK(l.pop_front() == i);

		CHECK(l.empty());
	}
}

TEST_CASE("Getting elements") {
	list l;

	SUBCASE("Getting at invalid position") {
		CHECK_THROWS(l.at(-1));
	}

	SUBCASE("Getting at valid positions") {
		const size_t test_size = 100;
		for (size_t i = 0; i < test_size; ++i)
			l.push_at_pos(i, i);

		for (size_t i = 0; i < test_size; ++i)
			CHECK(l.at(i) == i);
	}
}

TEST_CASE("Copying list") {
	list l = { 1,2,3,4,5 };
	list l_copy(l);

	SUBCASE("Size and elements match") {
		CHECK(l.size() == l_copy.size());

		for (size_t i = 0; i < l.size(); ++i)
			CHECK(l.at(i) == l_copy.at(i));
	}

	SUBCASE("Removing an element from copy doesn't affect the original") {
		l_copy.pop_back();
		CHECK(l.size() == l_copy.size() + 1);
	}
}

TEST_CASE("Reversing the list") {
	list l = { 0,1,2,3,4 };
	l.reverse();
	
	for (size_t i = 0; i < 5; ++i) {
		CHECK(l.at(i) == 5 - 1 - i);
	}
}

TEST_CASE("Removing repeating elements") {
	list set = { 0, 1, 2, 3, 4 };
	list multiset = { 0,0,1,2,3,4,3,1 };

	multiset.to_set();

	CHECK(set.size() == multiset.size());
}

TEST_CASE("Filtering list") {
	SUBCASE("Filtering a list to leave it empty") {
		list l = { 1 };
		l.filter([](const int& x) -> bool { return x % 2 == 0; });
		CHECK(l.empty());
	}

	SUBCASE("Filtering leaves correct elements") {
		list l = { 0,1,2,3,4,5,6,7,8,9 };
		list evens = { 0,2,4,6,8 };

		l.filter([](const int& x) -> bool { return x % 2 == 0; });

		CHECK(l.size() == evens.size());

		for (size_t i = 0; i < evens.size(); ++i) {
			CHECK(evens.at(i) == l.at(i));
		}
	}
}

TEST_CASE("Mapping a function on list") {
	list l = { 1,2,3,4,5 };
	list l_less = { 0,1,2,3,4 };

	l.map([](int& x) -> void { x = x - 1; });

	for (size_t i = 0; i < l.size(); ++i)
		CHECK(l_less.at(i) == l.at(i));
}