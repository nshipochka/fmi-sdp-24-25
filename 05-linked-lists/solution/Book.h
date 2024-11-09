#pragma once
#include <fstream>
#include <stdexcept>

class Book {
	static const size_t TITLE_SIZE = 30;
	static const size_t YEAR_SIZE = 4;

public:
	void deserialize(std::ifstream& in);
	friend std::ofstream& operator<<(std::ofstream& out, const Book& book);

private:
	char title[TITLE_SIZE + 1];
	char year[YEAR_SIZE + 1];
};

void Book::deserialize(std::ifstream& in) {
	in.read(year, YEAR_SIZE);
	year[YEAR_SIZE] = '\0';

	in.read(title, TITLE_SIZE);
	title[TITLE_SIZE] = '\0';
}

std::ofstream& operator<<(std::ofstream& out, const Book& book) {
	out << "    " << book.year << ' ' << book.title;
	return out;
}