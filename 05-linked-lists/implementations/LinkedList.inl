#include "LinkedList.h"
// Голяма 4-ка
template<typename T>
inline LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
	: LinkedList()
{
	for (const T& val : values)
		push_back(val);
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& other)
	: LinkedList()
{
	copy(other);
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

template<typename T>
inline LinkedList<T>::~LinkedList() {
	free();
}

// Четене на елемент
template<typename T>
inline const T& LinkedList<T>::front() const {
	return at(0);
}

template<typename T>
inline const T& LinkedList<T>::back() const {
	return at(sz - 1);
}

template<typename T>
inline const T& LinkedList<T>::at(size_t pos) const {
	if (empty() || pos >= sz)
		throw std::invalid_argument("Index out of bounds");

	// Отделяме частния случай, за да ни е бързо взимането на посл. елемент
	if (pos == sz - 1)
		return tail->data;

	const node* it = head;
	for (size_t i = 0; i < pos; ++i)
		it = it->next;

	return it->data;
}

// Добаваяне на елемент
template<typename T>
inline void LinkedList<T>::push_front(const T& val) {
	push_at_pos(0, val);
}

template<typename T>
inline void LinkedList<T>::push_back(const T& val) {
	push_at_pos(sz, val);
}

template<typename T>
inline void LinkedList<T>::push_at_pos(size_t pos, const T& val) {
	if (pos > sz)
		throw std::invalid_argument("Index out of bounds");

	if (pos == 0) {
		head = new node(val, head); // next-а на новата глава е предната глава
		if (sz == 0) tail = head; // Ако добавяме в празен списък
	}
	else if (pos == sz) {
		// Щом сме стигнали до тук, имаме гарантирано tail и tail->next няма да гръмне
		tail->next = new node(val);
		tail = tail->next;
	}
	else {
		node* it = head;
		for (size_t i = 0; i < pos - 1; ++i)
			it = it->next;

		it->next = new node(val, it->next);
	}

	++sz;
}

// Премахване на елемент
template<typename T>
inline T LinkedList<T>::pop_front() {
	return pop_at_pos(0);
}

template<typename T>
inline T LinkedList<T>::pop_back() {
	return pop_at_pos(sz - 1);
}

template<typename T>
inline T LinkedList<T>::pop_at_pos(size_t pos) {
	if (empty() || pos >= sz)
		throw std::invalid_argument("Index out of bounds");

	node* to_delete = head;
	if (pos == 0) {
		head = head->next;
		if (head == nullptr)
			tail == nullptr;
	}
	else {
		node* it = head;

		// Докато не стигнем предшественика на този, който трябва да изтрием
		for (size_t i = 0; i < pos - 1; ++i)
			it = it->next;

		to_delete = it->next;
		it->next = to_delete->next;

		if (it->next == nullptr) // Ако искаме да трием последния
			tail = it;
	}

	--sz;
	T stored_data = to_delete->data;
	delete to_delete;
	return stored_data;
}

template<typename T>
inline void LinkedList<T>::reverse() {
	// 1) Може с push/pop както правихме със стековете и опашките, но това са скъпи операци
	// 2) Може да "откачаме" елементи от началото и да ги "закачаме" в края
	// 3) Може да променим посоката, в която "сочат" указателите

	if (sz < 2)
		return;

	node* curr = head;
	node* prev = nullptr;
	node* next = nullptr;
	tail = head;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

// Пример за контролно
template<typename T>
inline void LinkedList<T>::to_set() {
	node* slow = head;
	node* fast = nullptr;

	while (slow && slow->next) {
		fast = slow;
		while (fast->next) {
			if (slow->data == fast->next->data) {
				node* to_delete = fast->next;
				fast->next = to_delete->next;
				--sz;
				delete to_delete;
			}
			else {
				fast = fast->next;
			}
		}
		slow = slow->next;
	}
	tail = slow;
}

template<typename T>
inline void LinkedList<T>::filter(bool(*f)(const T&)) {
	node* curr = head;
	node* prev = nullptr;

	while (curr) {
		if (!f(curr->data)) {
			node* to_delete = curr;
			curr = curr->next;

			if(prev)
				prev->next = curr;

			if (to_delete == head)
				head = curr;

			--sz;
			delete to_delete;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	tail = prev;
}

template<typename T>
inline void LinkedList<T>::map(void(*f)(T&)) {
	node* curr = head;

	while (curr) {
		f(curr->data);
		curr = curr->next;
	}
}

template<typename T>
inline void LinkedList<T>::copy(const LinkedList<T>& other) {
	// За да не пишем експлицитен случай, в който проверяваме дали добавяме първия елемент,
	// ще използваме фиктивен елемент, който да е този преди главата 
	node dummy;
	node* it = &dummy; // Сочи адреса на фиктивния елемент, с него ще итерираме тукашния списък
	node* curr = other.head; // С този указател ще итерираме подадения списък

	while (curr) { // Докато не обходим целия подаден списък
		it->next = new node(curr->data);
		it = it->next;
		curr = curr->next;
	}

	// Главата е първия "истински" елемент
	head = dummy.next;

	// Ako списъкът не е празен, it сочи последния елемент
	// Aко е празен, head и tail трябва да са nullptr
	tail = head ? it : nullptr;
	sz = other.sz;
}

// Помощни методи
template<typename T>
inline void LinkedList<T>::free() {
	node* it = head; // С този ще итерираме	
	node* to_delete = nullptr;

	while (it) {
		to_delete = it;
		it = it->next;
		delete to_delete;
	}

	tail = head = nullptr; // Иначе си сочат към места в паметта, които сме освободили
	sz = 0;
}