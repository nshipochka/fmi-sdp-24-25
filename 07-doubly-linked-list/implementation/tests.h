#pragma once
#include "../doctest.h"
#include "DoublyLinkedList.h"

typedef DoublyLinkedList<int> list;

TEST_CASE("Creating empty list") {
	list l;
	CHECK(l.is_empty());
}

TEST_CASE("Inserting an element makes the list non-empty") {
	list l;
	SUBCASE("Insert in front") {
		l.push_front(1);
		CHECK(!l.is_empty());
	}

	SUBCASE("Insert at back") {
		l.push_back(1);
		CHECK(!l.is_empty());
	}
}

TEST_CASE("Pushing elements") {
	SUBCASE("Pushing in empty list") {
		list l;

		SUBCASE("Pushing front") {
			l.push_front(1);
			CHECK(l.peek_front() == 1);
			CHECK(l.peek_back() == 1);
		}

		SUBCASE("Pushing back") {
			l.push_back(1);
			CHECK(l.peek_front() == 1);
			CHECK(l.peek_back() == 1);
		}
	}

	SUBCASE("Pushing in non-empty list") {
		list l({1});

		SUBCASE("Pushing front") {
			l.push_front(2);
			CHECK(l.peek_front() == 2);
			CHECK(l.peek_back() == 1);
		}

		SUBCASE("Pushing back") {
			l.push_back(2);
			CHECK(l.peek_front() == 1);
			CHECK(l.peek_back() == 2);
		}
	}
}

TEST_CASE("Popping elements") {
	SUBCASE("Popping from empty list") {
		list l;
		CHECK_THROWS(l.pop_back());
		CHECK_THROWS(l.pop_front());
	}

	SUBCASE("Popping from non-empty list") {
		list l({ 1,2 });

		SUBCASE("Popping front") {
			l.pop_front();
			CHECK(l.peek_front() == 2);
			CHECK(l.peek_back() == 2);
		}

		SUBCASE("Popping back") {
			l.pop_back();
			CHECK(l.peek_front() == 1);
			CHECK(l.peek_back() == 1);
		}
	}
}

TEST_CASE("Getting elements") {
	SUBCASE("Getting from empty list") {
		list l;

		CHECK_THROWS(l.peek_front());
		CHECK_THROWS(l.peek_back());
	}

	SUBCASE("Getting from non-empty list") {
		list l({ 1,2 });
		
		CHECK(l.peek_front() == 1);
		CHECK(l.peek_back() == 2);
	}
}

TEST_CASE("Copying list") {
	list l = { 1,2,3,4,5 };
	list l_copy(l);

	SUBCASE("Size and elements match") {
		CHECK(l.get_size() == l_copy.get_size());

		while (!l.is_empty()) {
			CHECK(l.peek_front() == l_copy.peek_front());
			CHECK(l.peek_back() == l_copy.peek_back());

			l.pop_front();
			l_copy.pop_front();
		}
	}

	SUBCASE("Removing an element from copy doesn't affect the original") {
		l_copy.pop_back();
		CHECK(l.get_size() == l_copy.get_size() + 1);
	}
}