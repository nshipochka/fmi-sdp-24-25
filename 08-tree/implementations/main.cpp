#include "BinaryTree.h"
#include "GeneralTree.h"

void print(int x) {
	std::cout << x << "__";
}

int main() {
	BinaryTree<int> bt(0,
		BinaryTree<int>(1, BinaryTree(11)),
		BinaryTree<int>(2, BinaryTree(21, BinaryTree(211), BinaryTree(212)), 
						   BinaryTree(22)));
	
	/*
	bt.map(print);
	std::cout << std::endl;

	const char* str = "node";
	bt.map([str](int x) { std::cout << x << " " << str << " "; });
	std::cout << std::endl;
	*/

	// Task 1
	bt.print_in_order();
	std::cout << std::endl;

	bt.print_pre_order();
	std::cout << std::endl;

	bt.print_post_order();
	std::cout << std::endl;

	// Task 2
	bt.trim();
	bt.map(print);
	std::cout << std::endl;

	// Task 3
	bt.bloom();
	bt.map(print);
	std::cout << std::endl;

	GeneralTree gt(0, GeneralTree(1, GeneralTree(11),
					  GeneralTree(2, GeneralTree(21, GeneralTree<int>(), GeneralTree(22)),
					  GeneralTree (3))));

	// Task 4
	std::cout << gt.branching_coeff();
	std::cout << std::endl;

	// Task 5
	gt.print_level(1);
	std::cout << std::endl;

	// Task 6
	std::cout << gt.leaf_count();
	std::cout << std::endl;

	return 0;
}