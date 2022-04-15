#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		if (t == 1) {
			cout << 1<<endl;
		}
		else {
			for (int i = 2; i <= t + 1; i++) {
				cout << i << " " ;
			}
			cout << endl;
		}
	}
}