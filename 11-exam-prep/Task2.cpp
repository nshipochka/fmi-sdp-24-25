#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>

using std::queue;
using std::vector;
using std::string;
using std::stringstream;

struct node {
	int data;
	vector<node*> children;

	node(int data = 0, vector<node*> children = vector<node*>())
		:data(data), children(children) {
	}
};

class Tree {
public:
	Tree() : name(""), root(nullptr) {}
	Tree(string name) : name(name) {
		try {
			read_from_file();
		}
		catch(std::exception& e){
			std::cerr << e.what();
			free(root);
		}
	}

	Tree(const Tree& other) {
		root = copy(other.root);
	}

	Tree& operator=(const Tree& other) {
		if (this != &other) {
			free(root);
			root = copy(other.root);
		}

		return *this;
	}

	~Tree() {
		free(root);
	}

	bool has_subtree(const Tree& other) {
		return has_subtree(root, other.root);
	}

	void remove_subtree(const Tree& other) {
		while (node* subtree = find_subtree(root, other.root)) {
			remove_subtree(subtree, other.root);
		}
	}

	void print_by_levels() const {
		if (!root) return;

		std::cout << "| " << root->data << " |\n";

		queue<node*> level;
		level.emplace(root);
		level.emplace(nullptr);

		while (!level.empty()) {
			node* current = level.front();
			level.pop();

			if (!current) {
				if (!level.empty()) {
					std::cout << "|";
					std::cout << std::endl;
					level.emplace(nullptr);
				}
			}
			else {
				std::cout << "| ";
				for (auto child : current->children) {
					std::cout << child->data << " ";
					level.emplace(child);
				}
			}
		}
	}

private:
	// Разделя низа на парчета според delimeter
	static vector<string> split(const string& str, char delimiter) {
		vector<string> tokens;
		stringstream ss(str);
		string token;

		while (getline(ss, token, delimiter))
			tokens.push_back(token);

		return tokens;
	}

	// Маха спейсовете от началото и края на низа
	static string trim(const string& str, char delimiter) {
		size_t start = str.find_first_not_of(delimiter);
		if (start == std::string::npos) {
			return str;
		}

		size_t end = str.find_last_not_of(delimiter);
		return str.substr(start, end - start + 1);
	}

	// Парсва групите деца от реда
	static vector<vector<node*>> parse_row(const string& row) {
		vector<vector<node*>> result;
		vector<string> segments = split(trim(row, '|'), '|');

		for (const string& segment : segments) {
			vector<node*> numbers;
			stringstream ss(trim(segment, ' '));
			int num;

			while (ss >> num)
				numbers.push_back(new node(num));

			result.push_back(numbers);
		}
		return result;
	}

	void read_from_file() {
		std::ifstream in(name);
		if (!in) return;

		string buff;
		queue<node*> parent_queue;
		
		// Първо четем корена
		getline(in, buff);
		vector<vector<node*>> root_level = parse_row(buff);

		if (root_level.empty() || root_level[0].empty())
			throw std::runtime_error("Invalid tree format: Missing root");
		
		root = root_level[0][0];
		parent_queue.push(root);

		// Четем останалите нива
		while (getline(in, buff)) {
			vector<vector<node*>> current_level = parse_row(buff);

			for (const auto& sibling_group : current_level) {
				if (parent_queue.empty())
					throw std::runtime_error("Invalid tree format: Not enough parents");

				node* parent = parent_queue.front();
				parent_queue.pop();

				parent->children = sibling_group;

				// Добавяме и децата за обработване
				for (node* child : sibling_group)
					parent_queue.push(child);
			}
		}

		in.close();
	}

	node* copy(const node* root) {
		if (!root) 
			return nullptr;

		vector<node*> children;
		for (auto child : root->children)
			children.push_back(copy(child));
	
		return new node(root->data, children);
	}

	void free(node*& root) {
		if (!root)
			return;

		for (auto child : root->children)
			free(child);

		delete root;
		root = nullptr;
	}

	node* find_subtree(node* root, node* other) {
		if (!root || !other)
			return nullptr;

		node* result = nullptr;
		if (root->data != other->data)
			for (auto child : root->children) {
				result = find_subtree(child, other);
				if (result)
					return result;
			}

		else {
			for (auto other_child : other->children) {
				auto match = find_if(root->children.begin(), root->children.end(), [other_child](const node* child) {
					return child->data == other_child->data; });

				while (match != root->children.end() && !has_subtree(*match, other_child)) {
					match = find_if(match, root->children.end(), [other_child](const node* child) {
						return child->data == other_child->data; });
				}

				// Ако match е стигнало края, значи или няма дете с такава стойност,
				// или за всички деца с такава стойност has_subtree е врърнало грешно 
				if (match == root->children.end())
					return nullptr;
			}

			// Ако сме стигнали дотук, всички деца, които е трябвало, са се оказали поддървета
			return root;
		}
	}

	bool has_subtree(node* root, node* other) {
		//if (!root)
		//	return false;

		//if (!other)
		//	return true;

		//bool result = false;

		//if (root->data != other->data)
		//	for (auto child : root->children)
		//		result = result || has_subtree(child, other);
		//// Попданали сме на потеницално място, където може да е поддърво
		//else {
		//	for (auto other_child : other->children) {
		//		auto match = find_if(root->children.begin(), root->children.end(), [other_child](const node* child) {
		//			return child->data == other_child->data; });

		//		while (match != root->children.end() && !has_subtree(*match, other_child)) {
		//			match = find_if(match, root->children.end(), [other_child](const node* child) {
		//				return child->data == other_child->data; });
		//		}

		//		// Ако match е стигнало края, значи или няма дете с такава стойност,
		//		// или за всички деца с такава стойност has_subtree е врърнало грешно 
		//		if (match == root->children.end())
		//			return false;
		//	}
		//}

		//// Ако сме стигнали дотук, всички деца, които е трябвало, са се оказали поддървета
		//return true;

		return find_subtree(root, other);
	}

	int tree_sum(node* root) const {
		if (!root)
			return 0;

		int sum = 0;
		for (auto child : root->children)
			sum += tree_sum(child);

		return root->data + sum;
	}

	int remove_subtree(node* root, node* other) {
		if (!root)
			return 0;


	}


	string name;
	node* root;
};

int main() {
	
	Tree t("input.txt");
	t.print_by_levels();
	std::cout << std::endl;

	Tree t2("input2.txt");
	t2.print_by_levels();
	std::cout << std::endl;

	std::cout << t.has_subtree(t2);

	return 0;
}