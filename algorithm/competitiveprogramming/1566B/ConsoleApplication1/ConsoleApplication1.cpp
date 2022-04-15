#include<bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	cin >> s;
	int zeroes = count(s.begin(), s.end(), '0');
	if (!zeroes) {
		cout << 0 << endl;
	}
	else {
		int first = s.find('0');
		int last = s.rfind('0');
		if (last - first + 1 == zeroes) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}

}
int main() {
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
}