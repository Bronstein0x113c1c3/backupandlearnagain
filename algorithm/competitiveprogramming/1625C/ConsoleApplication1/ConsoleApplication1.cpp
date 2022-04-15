
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> coordinate(n + 1);
	vector<int> speedlimit(n + 1);
	vector<vector<int>> dp;
	dp.resize(n+1,vector<int>(l+1,INT_MAX));
	for (int i = 0; i < n; i++) {
		cin >> coordinate[i];
	}
	coordinate[n] = l;
	for (int i = 0; i < n; i++) {
		cin >> speedlimit[i];
	}
	speedlimit[n] = 0;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + speedlimit[i - 1] * (coordinate[i] - coordinate[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j]==INT_MAX) continue;
			for (int pos = i + 1; (pos <= n); pos++) {
				if (j + pos - i - 1 <= k) {
					dp[pos][pos - i - 1 + j] = min(dp[pos][j + pos - i - 1], dp[i][j] + speedlimit[i] * (coordinate[pos] - coordinate[i]));
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= k; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans;

}

