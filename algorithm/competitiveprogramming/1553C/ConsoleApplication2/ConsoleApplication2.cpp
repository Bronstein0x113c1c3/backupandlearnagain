// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int ans = 9;
    string s;
    cin >> s;
    {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) cnt0 += s[i] == '1';
            else cnt1 += s[i] != '0';
            if (cnt0 > cnt1 + (10 - i) / 2) ans = min(ans, i);
            if (cnt1 > cnt0 + (9 - i) / 2) ans = min(ans, i);
        }
    }
    {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) cnt0 += s[i] != '0';
            else cnt1 += s[i] == '1';
            if (cnt0 > cnt1 + (10 - i) / 2) ans = min(ans, i);
            if (cnt1 > cnt0 + (9 - i) / 2) ans = min(ans, i);
        }
    }
    cout << ans+1 << endl;





}
int main()
{
    int test;
    cin >> test;
    while (test--) {
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
