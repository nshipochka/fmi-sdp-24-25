#include "Library.h"

int main() {
	Library lib("authors.dat");
	lib.filter([](const Author& a) -> bool {
			return a > 'H';
		});

	return 0;
}
