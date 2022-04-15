// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = res & a[i];
    }
    cout << res << endl;
}
int main()
{
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}

