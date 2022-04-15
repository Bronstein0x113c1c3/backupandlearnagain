// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int inf = 10000000;
    int n;
    cin >> n;
    vector<int> a(n);
    int maxl = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxl = max(maxl, a[i]);
    }
    vector<vector<int>>dp(n + 1, vector<int>(2 * maxl + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * maxl; j++) {
            if (dp[i][j] == inf) continue;
            dp[i + 1][max(0, j - a[i])] = min(dp[i + 1][max(0, j - a[i])], dp[i][j] + a[i]);
            if (j + a[i] < dp[i + 1].size()) {
                dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(0, dp[i][j] - a[i]));
            }
        }
    }
    int ans = 2 * maxl + 1;
    for (int i = 0; i <= 2 * maxl; i++) {
        ans = min(ans, i + dp[n][i]);
    }
    cout << ans<<endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
