// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n>>k;
    int awake = 0;
    vector<int> a(n);
    vector<int> t(n);
    vector<int> asleep(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    asleep[0] = t[0] > 0 ? 0 : a[0];
    awake = t[0] > 0 ? a[0] : 0;
    for (int i = 1; i < n; i++) {
        if (t[i] == 0) {
            asleep[i] = asleep[i - 1] + a[i];
        }
        else { awake += a[i]; asleep[i] = asleep[i - 1]; }
    }
    int add = 0;
    for (int j = k - 1; j < n; j++) {
        add = max(add, asleep[j] - (j >= k ? asleep[j - k] : 0));
    }
    cout << awake + add<<endl;





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
