// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 4);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int64_t> d1(n + 4), d2(n + 4);
    d1[0] = -static_cast<int64_t>(1e18);
    d2[0] = 0;
    for (int i = 0; i < n; i++) {
        d1[i + 1] = max(d1[i], d2[i] + a[i+1]);
        d2[i + 1] = max(d2[i], d1[i] - a[i + 1]);
    }
    cout << max(d2[n], d1[n]) << endl;
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
