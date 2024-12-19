#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <string>
#include <sstream>

using std::vector;
using std::pair;
using std::array;
using std::string;
using std::stringstream;

enum Drinks {
	NONE = -1,

	BEER,
	VODKA,
	WHISKEY,
	TEQUILA,
	COLA,
	RUM,
	GIN,
	MINT,

	COUNT
};

const array<string, COUNT> drinks = 
	{ "beer", "vodka", "whiskey", "tequila", "cola", "rum", "gin", "mint" };

struct BarSlot {
	vector<Drinks> available_drinks;
	BarSlot* next;

	bool is_available;

	BarSlot(const vector<Drinks>& drinks = vector<Drinks>(), BarSlot* next = nullptr, bool is_available = true)
		: available_drinks(drinks), next(next), is_available(is_available) {
	}
};

struct Client {
	vector<Drinks> favourite_drinks;
	
	Client* prev;
	Client* next;

	bool is_seated;

	Client(const vector<Drinks>& drinks = vector<Drinks>(), Client* prev = nullptr, Client* next = nullptr, bool is_seated = false)
		: favourite_drinks(drinks), prev(prev), next(next), is_seated(is_seated) {
	}
};


BarSlot* create_bar(std::initializer_list<pair<vector<Drinks>, bool>> list) {
	BarSlot dummy;
	BarSlot* curr = &dummy;
	for (auto element : list) {
		curr->next = new BarSlot(element.first, nullptr, element.second);
		curr = curr->next;
	}

	return dummy.next;
}

Client* create_group(std::initializer_list<pair<vector<Drinks>, bool>> list) {
	Client dummy;
	Client* curr = &dummy;
	for (auto element : list) {
		curr->next = new Client(element.first, curr, nullptr, element.second);
		curr = curr->next;
	}

	dummy.next->prev = nullptr;
	return dummy.next;
}

void clear(BarSlot*& head) {
	BarSlot* curr = head;

	while (curr) {
		BarSlot* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}

	head = nullptr;
}

void clear(Client*& head) {
	Client* curr = head;

	while (curr) {
		Client* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}

	head = nullptr;
}

bool drinks_available(const vector<Drinks>& bar, const vector<Drinks>& client) {
	for (auto drink : client) {
		if (find(bar.begin(), bar.end(), drink) == bar.end())
			return false;
	}

	return true;
}

bool place(BarSlot* bar, Client* clients) {
	// bar == nullptr, clients == nullptr;

	int skipped_seats = 0;

	while (bar && clients) {
		if (bar->is_available && drinks_available(bar->available_drinks, clients->favourite_drinks)) {
			bar->is_available = false;
			clients->is_seated = true;
			clients = clients->next;
			skipped_seats = 0;
		}
		else {
			skipped_seats++;
		}

		if (skipped_seats > 5)
			return false;

		bar = bar->next;
	}

	if (!clients)
		return true;

	return false;
}

template <typename T>
void get_permutations(vector<vector<T>>& res, vector<T> arr, int index) {
	if (index == arr.size()) {
		res.push_back(arr);
		return;
	}

	// Този индекс сложен на всяка възможна позиция до края
	for (int i = index; i < arr.size(); i++) {
		std::swap(arr[index], arr[i]);
		get_permutations(res, arr, index + 1);

		// Backtracking
		std::swap(arr[index], arr[i]);
	}
}

BarSlot* copy(const BarSlot* bar) {
	BarSlot* bar_copy = nullptr;
	while (bar) {
		bar_copy = new BarSlot(bar->available_drinks, bar_copy, bar->is_available);
		bar = bar->next;
	}

	return bar_copy;
}

bool place_permutation(BarSlot* bar, vector<Client*> groups) {
	for (int i = 0; i < groups.size(); ++i) {
		if (!place(bar, groups[i]))
			return false;
	}
	return true;
}

bool placeAll(BarSlot* bar, vector<Client*> groups) {
	vector<vector<Client*>> permutations;
	get_permutations(permutations, groups, 0);

	for (size_t i = 0; i < permutations.size(); ++i) {
		BarSlot* bar_copy = copy(bar);
		if (place_permutation(bar_copy, permutations[i])) {
			clear(bar_copy);
			return true;
		}
		clear(bar_copy);
	}

	return false;
}

bool place_all_no_perm() {
	
}

int main() {
	BarSlot* bar = create_bar({ 
		{{VODKA, COLA, RUM}, true}, 
		{{GIN, BEER, WHISKEY, COLA, MINT}, true},
		{{BEER, VODKA, WHISKEY, TEQUILA, COLA, RUM, GIN, MINT}, true},
		{{BEER, WHISKEY, TEQUILA, COLA, RUM, GIN, MINT}, true},
		{{BEER, VODKA, WHISKEY, RUM, GIN, MINT}, true},
		{{BEER, VODKA, WHISKEY}, true},
		{{WHISKEY, TEQUILA, COLA, GIN, MINT}, true},
		{{VODKA, WHISKEY, TEQUILA, COLA, RUM, GIN}, true}
	});

	Client* group1 = create_group({
		{{VODKA}, false},
		{{VODKA}, false},
		{{BEER, VODKA}, false},
		{{BEER, VODKA}, false}
	});

	Client* group2 = create_group({
		{{COLA}, false},
		{{GIN, COLA}, false}
		});

	vector<Client*> groups = { group1, group2 };

	std::cout << placeAll(bar, groups);

	clear(bar);
	clear(group1);
	clear(group2);

	return 0;
}