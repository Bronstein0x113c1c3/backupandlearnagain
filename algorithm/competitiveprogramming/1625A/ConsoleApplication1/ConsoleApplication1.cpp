// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, l,ans = 0;
    cin >> n >> l;
    vector<int> a(n);
    int max1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max1 = max(max1, a[i]);
    }
    l = log2(max1)+1;
    for (int index = 0; index < l; index++) {
        int differ1 = 0;
        for (int num = 0; num < n; num++) {
            if ((a[num] >> index) & 1) {
                differ1++;
            }
        }
        if (differ1 > n - differ1) {
            ans += pow(2,index);
        }
    }
    cout << ans<<endl;
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
