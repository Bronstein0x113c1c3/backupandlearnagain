// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int addi = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i - 1] < k) {
            addi += k - (a[i] + a[i - 1]);
            a[i] = k - a[i - 1];
        }
    }
    cout << addi << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
