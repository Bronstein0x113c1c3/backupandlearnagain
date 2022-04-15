// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int prev = 0, ans = 0, ok = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ans += (a != prev);
        ok |= a == prev;
        if (prev + 1 < a) {
            ans += ok;
            ok = 0;
        }
        prev = a;
    }
    ans += ok;
    cout << ans << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}

