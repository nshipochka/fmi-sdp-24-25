#include "CircularQueue.h"
#include "LinkedQueue.h"
#include <iostream>

int main() {
	CircularQueue<int> cq(12);
	cq.enqueue(1);
	std::cout << cq.first() << std::endl;

	LinkedQueue<char> lq;
	lq.enqueue('l');
	lq.enqueue('q');
	std::cout << lq.first() << std::endl;

	return 0;
}