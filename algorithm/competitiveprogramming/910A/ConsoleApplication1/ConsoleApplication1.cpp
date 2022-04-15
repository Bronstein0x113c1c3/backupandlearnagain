// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int max = 1000;
    int n, d;
    string s;
    cin >> n >> d;
    cin >> s;
    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1000;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= d; j++) {
            if ((i + j < n)&&(s[i+j]=='1')) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
    }
    if (dp[n - 1] == 1000) {
        cout << -1;
    }
    else {
        cout << dp[n - 1];
    }
}

