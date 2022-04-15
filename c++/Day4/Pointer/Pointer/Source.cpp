#include<iostream>
#include<conio.h>

void swap(int* a, int* b) {		//int* is pointer type of C++, a and b are the pointers
	int m = *a;				//int m = *a, so the type of *a is integer, m is also an integer number
	*a = *b;				// when *a= *b, it transfers not only the value but more important, is the memory address, 
	*b = m;						////which ordinary variable can't do.
	
}
int main() {
	int n;
	int a[100];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				swap(&a[i], &a[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}

}