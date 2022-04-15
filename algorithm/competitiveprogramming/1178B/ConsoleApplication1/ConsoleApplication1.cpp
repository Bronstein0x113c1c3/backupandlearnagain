#include<bits/stdc++.h>
using namespace std;
int main() {
	string m; 
	cin >> m;
	long long a = 0, b = 0, ans = 0;
	for (int i = 0; i < m.length(); i++) {
		if (m[i] == 'o') {
			b += a;
		}
		else if ((i > 0) && (m[i - 1] == 'v')) {
			ans += b;
			a++;
		}
	}
	cout << ans << endl;
}