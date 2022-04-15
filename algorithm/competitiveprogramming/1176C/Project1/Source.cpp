#include<iostream>
using namespace std;
int dp[6];
int index[43];
int a[500005];
int main() {
	int n;
	int maxi = 0;
	index[4] = 0;
	index[8] = 1;
	index[15] = 2;
	index[16] = 3;
	index[23] = 4;
	index[42] = 5;
	cin >> n;
	int i;

	for (int j = 0; j < n; j++) {
		cin >> i;
		a[j] = index[i];
		if (a[j] == 0) {
			dp[0]++;
		}
		else {
			if (dp[a[j] - 1] > 0) {
				dp[a[j] - 1]--;
				dp[a[j]]++;
			}
		}
	}
	cout << n - 6 * dp[5]<<endl;
}