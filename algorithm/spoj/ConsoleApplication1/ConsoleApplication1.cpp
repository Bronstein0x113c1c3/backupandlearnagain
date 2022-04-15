// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<gr>
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int price[105];
    price[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> price[i];
        if (price[i] == -1) price[i] = 1000000;
    }
    int dp[105];
    memset(dp, int(1e6), sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i] = min(dp[i],dp[j] + price[i - j]);
        }
    }
    if (dp[k] >= 1000000) {
        dp[k] = -1;
        cout << dp[k] << endl;
    }
    else {
        cout << dp[k] << endl;
    }
}
int main()
{
    int tests;
    cin >> tests;
    while (tests--) {
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
