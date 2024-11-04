#pragma once
#include "../doctest.h"
#include "CircularDeque.h"

TEST_CASE_TEMPLATE("Creating empty Deque", Deque, CircularDeque<int>) {
    Deque q;
    CHECK(q.empty());
}

TEST_CASE_TEMPLATE("When element is inserted, the Deque isn't empty", Deque, CircularDeque<int>) {
    Deque q;
    
    SUBCASE("push_front()") {
        q.push_front(1);
        CHECK(!q.empty());
    }

    SUBCASE("push_back()") {
        q.push_front(1);
        CHECK(!q.empty());
    }
}

TEST_CASE_TEMPLATE("Remove element from empty Deque", Deque, CircularDeque<int>) {
    Deque q;
    CHECK_THROWS(q.pop_front());
    CHECK_THROWS(q.pop_back());
}

TEST_CASE_TEMPLATE("Getting front/back element from an empty Deque", Deque, CircularDeque<int>) {
    Deque q;
    CHECK_THROWS(q.front());
    CHECK_THROWS(q.back());
}

TEST_CASE_TEMPLATE("When inserting an element in front, it is the front", Deque, CircularDeque<int>) {
    Deque q;
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);
    CHECK(q.front() == 3);
    CHECK(q.back() == 1);
}

TEST_CASE_TEMPLATE("When inserting an element at the back, it is the back", Deque, CircularDeque<int>) {
    Deque q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    CHECK(q.back() == 3);
    CHECK(q.front() == 1);
}

TEST_CASE_TEMPLATE("When inserting elements in front, they pop_back() in the same order and pop_front() in the opposite", Deque, CircularDeque<int>) {
    SUBCASE("pop_front() in the opposite order") {
        Deque q;
        q.push_front(1);
        q.push_front(2);
        q.push_front(3);

        CHECK(q.pop_front() == 3);
        CHECK(q.pop_front() == 2);
        CHECK(q.pop_front() == 1);
    }

    SUBCASE("pop_back() in the same order") {
        Deque q;
        q.push_front(1);
        q.push_front(2);
        q.push_front(3);

        CHECK(q.pop_back() == 1);
        CHECK(q.pop_back() == 2);
        CHECK(q.pop_back() == 3);
    }
}

TEST_CASE_TEMPLATE("When inserting elements at the back, they pop_front() in the same order and pop_back() in the opposite", Deque, CircularDeque<int>) {
    SUBCASE("pop_front() in the same order") {
        Deque q;
        q.push_back(1);
        q.push_back(2);
        q.push_back(3);

        CHECK(q.pop_front() == 1);
        CHECK(q.pop_front() == 2);
        CHECK(q.pop_front() == 3);
    }

    SUBCASE("pop_back() in the opposite order") {
        Deque q;
        q.push_back(1);
        q.push_back(2);
        q.push_back(3);

        CHECK(q.pop_back() == 3);
        CHECK(q.pop_back() == 2);
        CHECK(q.pop_back() == 1);
    }
}

TEST_CASE_TEMPLATE("Multiple times inserting and removing an element", Deque, CircularDeque<int>) {
    SUBCASE("Inserting back") {
        Deque q;
        for (int i = 0; i < 1000; i++) {
            q.push_back(i);
            CHECK(q.pop_back() == i);
        }
        CHECK(q.empty());
    }

    SUBCASE("Inserting front") {
        Deque q;
        for (int i = 0; i < 1000; i++) {
            q.push_front(i);
            CHECK(q.pop_front() == i);
        }
        CHECK(q.empty());
    }
}

TEST_CASE("Inserting MAX - 1 elements throws exception: full Deque") {
    
    SUBCASE("Inserting back") {
        CircularDeque<int> q;
        for (int i = 0; i < q.get_size() - 1; i++) {
            q.push_back(i);
        }
        CHECK_THROWS(q.push_back(0));
    }

    SUBCASE("Inserting front") {
        CircularDeque<int> q;
        for (int i = 0; i < q.get_size() - 1; i++) {
            q.push_front(i);
        }
        CHECK_THROWS(q.push_front(0));
    }
}
