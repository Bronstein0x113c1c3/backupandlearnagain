#include<iostream>
using namespace std;
int main() {
	int n;
	int count = 0;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		count += i * (i - 1);
	}
	cout << count << endl;
}