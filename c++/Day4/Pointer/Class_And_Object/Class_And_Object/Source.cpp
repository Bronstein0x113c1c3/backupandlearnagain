#include<iostream>
using namespace std;
class Book {
	public: //public entity
		void info() {
			cout << this->author << " " << this->title << " " << this->pages<<" "<<this ->Rating;
		}
		string Rating;
		string title;
		string author;
		int pages;
		Book(string title,string author,int pages, string Rating) {
			this->title = title;
			this->author = author;
			this->pages = pages;
			change_unknown_rating(Rating);
			this->Rating = this->rating;
		}
		void change_unknown_rating(string Rating) {
			this->rating = (Rating == "G" || Rating == "PG" || Rating == "PG-13" || Rating == "R" || Rating == "NR") ? Rating : "NR";
		}
	private: //private entities (allowed to adjust inside the class, not outside)
		string rating;
		
};
int main() {
	Book book1("Harry Potter", "J.K Rowling", 400,"Dog");
	book1.info();

}