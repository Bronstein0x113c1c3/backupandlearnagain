#include <iostream>
using namespace std;
const int maxn = 505;
int a[maxn];
int tot;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	tot = 0;
	for (int i = 1; i < n; i++)
		if (a[i - 1] + a[i] < m) {
			tot += m - a[i] - a[i - 1];
			a[i] = m - a[i - 1];
		}

	cout << tot << endl;
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
	return 0;
}