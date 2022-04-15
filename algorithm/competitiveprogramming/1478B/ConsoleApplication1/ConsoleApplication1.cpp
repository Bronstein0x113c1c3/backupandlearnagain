// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int q, d;
    cin >> q >> d;
    int maxd = d * 10;
    vector<int> check(maxd + 1);
    check[0] = 1;
    for (int i = 0; 10 * i + d <= maxd; i++) {
        for (int j = 0; 10 * i + d + j <= maxd; j++) {
            check[10 * i + d + j] |= check[j];
        }
    }
    while (q--) {
        int a;
        cin >> a;
        if (a >= maxd || check[a]) {
            cout << "YES \n";
        }
        else {
            cout << "NO \n";
        }
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
