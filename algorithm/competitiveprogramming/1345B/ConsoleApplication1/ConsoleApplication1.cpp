#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int maxh = 0;
	for (int i = 0; i * (i + 1) + i * (i - 1) / 2 <= n; i++) {
		maxh = i;
	}
	int quantity = 0;
	while ((n>0)&&(maxh>0)) {
		while (n >= maxh * (maxh + 1) + maxh * (maxh - 1) / 2) {
			quantity++;
			n -= maxh * (maxh + 1) + maxh * (maxh - 1) / 2;
		}
		maxh--;
	}
	cout << quantity<<endl;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
}