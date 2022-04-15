#include<bits/stdc++.h>
using namespace std;
int main() {
	string m;
	cin >> m;
	long long ans = 0;
	for (int i = 0; i < m.length(); i++) {
		if (int(m[i] - '0') % 4 == 0) {
			ans++;
		}
		if ((i > 0) && ((int(m[i - 1] - '0') * 10 + int(m[i] - '0')) % 4 == 0)) {
			ans = ans + i;
		}
	}
	cout << ans << endl;
}