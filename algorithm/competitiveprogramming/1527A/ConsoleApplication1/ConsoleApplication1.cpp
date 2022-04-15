#include<bits/stdc++.h>
using namespace std;
void solve() {
	long long n;
	cin >> n;
	int last = 0;
	for (int i = 1; i < 30; i++) {
		if ((n >> i) & 1 == 1) {
			last = i;
		}
	}
	cout << (1 << last) - 1 << endl;
		
}
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		solve();
	}
}