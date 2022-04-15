// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> dp(n,0);
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] + i >= n) {
			dp[i] = a[i];
		}
		else {
			dp[i] = dp[i + a[i]] + a[i];
		}
		if (dp[i] >= max){
			max = dp[i];
		}
	}
	cout << max << endl;
}
int main()
{
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
}

