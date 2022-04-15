#include<iostream>
using namespace std;
int main() {
	string a, b;
	int count = 0;
	int n;
	cin >> n;
	cin >> a >> b;
	int i = 0;
	while (i<n) {
		if (a[i] == b[i]) i++;
		else {
			if ((i + 1 < n) && (a[i + 1] != b[i + 1]) && (a[i + 1] != a[i])) {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
	}
	cout << count;
}