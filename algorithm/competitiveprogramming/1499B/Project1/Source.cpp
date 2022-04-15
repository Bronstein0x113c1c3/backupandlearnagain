#include<iostream>
using namespace std;
void solve() {
	string s;
	cin >> s;
	string m = "YES";
	int index1 = s.length(), index0 = 0;

	for (int count = 0; count < s.length() - 1; count++) {
		if (s[count] == s[count + 1]) {
			if (s[count] == '0') {
				index0 = count;
			}
			else {
				index1 = count;
			}
			if (index1 - index0 < 0) {
				m = "NO";
				break;
			}
		}
	}
	cout << m << endl;

}
int main() {
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
}