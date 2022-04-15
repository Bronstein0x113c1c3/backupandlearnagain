#include <iostream>

using namespace std;
class Book {
public:
	string title;
	string author;
	int pages;
	void info() {
		cout << title;
	}
	Book(string title, string author, int pages) {
		this->title = title;
		this->author = author;
		this->pages = pages;
	}
};
int main() {
	Book book1("Network Programming","Kurose",800);
	
}